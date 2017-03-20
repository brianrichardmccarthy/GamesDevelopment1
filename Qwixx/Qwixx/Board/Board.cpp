#include "Board.h"
namespace board {

    void Board::updateBoardToString() {
        m_boardToString = "";
        for (unsigned int x = 0; x < m_rows.size(); x++)
            m_boardToString += m_rows.at(x).toString() + "\n";

        m_boardToString += "\n";

        for (unsigned int x = 0; x < m_dices.size(); x++)
            m_boardToString += m_dices.at(x).toString() + "\n";

        m_boardToString += "\n";
    }
    
    Board::Board() {
        m_dices.push_back(die::Die("White"));
        m_dices.push_back(die::Die("White"));
        m_dices.push_back(die::Die("Red"));
        m_dices.push_back(die::Die("Green"));
        m_dices.push_back(die::Die("Blue"));
        m_dices.push_back(die::Die("Yellow"));

        m_rows.push_back(row::Row(2, 1, "Red"));
        m_rows.push_back(row::Row(2, 1, "Yellow"));
        m_rows.push_back(row::Row(12, -1, "Green"));
        m_rows.push_back(row::Row(12, -1, "Blue"));
    }

    Board::~Board() {
    }
    
    void Board::display() {
        std::cout << m_boardToString << std::endl;
    }
    
    bool Board::mark(unsigned int index, std::string color) {
        for (unsigned int x = 0; x < m_rows.size(); x++)
            if (m_rows.at(x).getColor() == color)
                if (m_rows.at(x).mark(index)) {
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
}