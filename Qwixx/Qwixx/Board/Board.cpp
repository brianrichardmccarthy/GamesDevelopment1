#include "Board.h"
namespace board {

    Board::Board() {
        m_dices.push_back(die::Die("White"));
        m_dices.push_back(die::Die("White"));
        m_dices.push_back(die::Die("Red"));
        m_dices.push_back(die::Die("Green"));
        m_dices.push_back(die::Die("Blue"));
        m_dices.push_back(die::Die("Yellow"));
    }

    Board::~Board() {
    }
    
    void Board::display() {
        std::cout << m_boardToString << std::endl;
    }
    
    void Board::updateBoardToString() {
        m_boardToString = "Computer\n";
        for (unsigned int x = 0; x < computerPlayer.m_rows.size(); x++)
            m_boardToString += computerPlayer.m_rows.at(x).toString() + "\n";

        m_boardToString += "\nPlayer\n";
        for (unsigned int x = 0; x < humanPlayer.m_rows.size(); x++)
            m_boardToString += humanPlayer.m_rows.at(x).toString() + "\n";
        
        m_boardToString += "\nDice\n";
        for (unsigned int x = 0; x < m_dices.size(); x++)
            m_boardToString += m_dices.at(x).toString() + "\n";

        m_boardToString += "\n";
    }
    
    bool Board::mark(unsigned int index, std::string color, std::string player) {
        for (unsigned int x = 0; x < Card::ROWS; x++)
            if (player == "human")
                if (humanPlayer.m_rows.at(x).getColor() == color)
                    if (humanPlayer.m_rows.at(x).mark(index)) {
                        if (humanPlayer.m_rows.at(x).isRowClosed())
                            computerPlayer.m_rows.at(x).closeRow();
                        
                        updateBoardToString();
                        return true;

                    }
            else
                if (computerPlayer.m_rows.at(x).getColor() == color)
                    if (computerPlayer.m_rows.at(x).mark(index)) {
                        if (computerPlayer.m_rows.at(x).isRowClosed())
                            humanPlayer.m_rows.at(x).closeRow();
                        updateBoardToString();
                        return true;
                    }

        return false;
    }
    
    void Board::roll() {
        srand(static_cast<unsigned int>(time(0)));
        for (unsigned int x = 0; x < m_dices.size(); x++)
            m_dices.at(x).roll();

        updateBoardToString();
    }
    void Board::update() {

        roll();
        display();

    }

    void Board::endGame() {
        m_gamestates = WIN;
    }

    Board::Card::Card() {
        m_rows.push_back(row::Row(2, 1, "Red"));
        m_rows.push_back(row::Row(2, 1, "Yellow"));
        m_rows.push_back(row::Row(12, -1, "Green"));
        m_rows.push_back(row::Row(12, -1, "Blue"));
    }
    Board::Card::~Card() {
    }
}