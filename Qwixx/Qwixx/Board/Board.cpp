#include "Board.h"
namespace board {

    Board::Board() {
        // creates the dices
        m_dices.push_back(die::Die("Red"));
        m_dices.push_back(die::Die("Yellow"));
        m_dices.push_back(die::Die("Green"));
        m_dices.push_back(die::Die("Blue"));
        m_dices.push_back(die::Die("White"));
        m_dices.push_back(die::Die("White"));
    }

    Board::~Board() {
    }
    
    void Board::display() {
        // print the board as string
        std::cout << m_boardToString << std::endl;
    }
    
    void Board::updateBoardToString() {

        // put the computers' rows into the string
        m_boardToString = "\tComputer\n\t--------\n";
        for (unsigned int x = 0; x < computerPlayer.m_rows.size(); x++)
            m_boardToString += computerPlayer.m_rows.at(x).toString() + "\n";

        // put the players' rows into the string
        m_boardToString += "\n\tPlayer\n\t------\n";
        for (unsigned int x = 0; x < humanPlayer.m_rows.size(); x++)
            m_boardToString += humanPlayer.m_rows.at(x).toString() + "\n";
        
        // put the dices into the string
        m_boardToString += "\nDice\n";
        for (unsigned int x = 0; x < m_dices.size(); x++)
            m_boardToString += m_dices.at(x).toString() + "\n";

        // put an extra new line just because
        m_boardToString += "\n";
    }
    
    bool Board::mark(const unsigned int& index, const std::string& color, const std::string& player) {
        
        /*
            Loop throught the rows to find the given color,
                Depending on player update either the human board or computer
                Place a mark on their row at the given index
                Then check if that mark closes the row
                    if yes then close the other players row and close the die
                Finally update boards' string representation
            
            For this loop i didn't use an iterator because using an int and the way the rows and dices are create
            at each value of the int match eg Red die and Red Row at 0 and so on
        */
        for (unsigned int x = 0; x < Card::ROWS; x++)
            if (player == "human") {
                if (humanPlayer.m_rows.at(x).getColor() == color) {
                    if (humanPlayer.m_rows.at(x).mark(index, m_dices.at(x).getLowest())) {
                        if (humanPlayer.m_rows.at(x).isRowClosed()) {
                            computerPlayer.m_rows.at(x).closeRow();
                            m_dices.at(x).closeDie();
                        }

                        updateBoardToString();
                        return true;

                    }
                }
            } else {
                if (computerPlayer.m_rows.at(x).getColor() == color) {
                    if (computerPlayer.m_rows.at(x).mark(index, m_dices.at(x).getLowest())) {
                        if (computerPlayer.m_rows.at(x).isRowClosed()) {
                            humanPlayer.m_rows.at(x).closeRow();
                            m_dices.at(x).closeDie();
                        }
                        updateBoardToString();
                        return true;
                    }
                }
            }

        return false;
    }
    
    void Board::roll() {

        // seed the random
        srand(static_cast<unsigned int>(time(0)));
        
        // loop through the dices and roll them
        std::vector<die::Die>::iterator iter;
        for (iter = m_dices.begin(); iter != m_dices.end(); iter++)
            iter->roll();

        // ToDo
        // std::vector<row::Row>::const_iterator iter2;
        
        // Set the lowest value for the second play
        for (iter = m_dices.begin() /*, iter2 = humanPlayer.m_rows.begin()*/; iter != m_dices.end() - 2 /* && iter2 != humanPlayer.m_rows.end(); iter2++,*/; iter++) {
            // iter->setValid(((iter->getTop() + m_dices.at(m_dices.size() - 2).getTop())  >= iter2->getIndex()) || ((iter->getTop() + m_dices.at(m_dices.size() - 1).getTop()) >= iter2->getIndex()));
            if (iter->getTop() + m_dices.at(m_dices.size() - 2).getTop() < iter->getTop() + m_dices.at(m_dices.size() - 1).getTop())
                iter->setLowest(iter->getTop() + m_dices.at(m_dices.size() - 2).getTop());
            else
                iter->setLowest(iter->getTop() + m_dices.at(m_dices.size() - 1).getTop());
        }

        // Update the two white dies lowest value
        iter->setLowest(iter->getTop() + (iter+1)->getTop());
        ++iter;
        iter->setLowest(iter->getTop() + (iter - 1)->getTop());

        updateBoardToString();
    }

    void Board::update() {

        // roll and display the board
        roll();
        display();
    }

    void Board::endGame() {
        // change the state to end the game
        // ToDo: get the board to check if the game is over
        m_gamestates = WIN;
    }

    Board::Card::Card() {
        // create the rows
        m_rows.push_back(row::Row(2, 1, "Red"));
        m_rows.push_back(row::Row(2, 1, "Yellow"));
        m_rows.push_back(row::Row(12, -1, "Green"));
        m_rows.push_back(row::Row(12, -1, "Blue"));
    }

    Board::Card::~Card() {
    }
}