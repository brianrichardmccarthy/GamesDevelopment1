#include "Board.h"
namespace board {

    void Board::updateBoardToString() {
        boardToString = "";
        for (unsigned int x = 0; x < rows.size(); x++)
            boardToString += rows.at(x).toString() + "\n";

        boardToString += "\n";

        for (unsigned int x = 0; x < dices.size(); x++)
            boardToString += dices.at(x).toString() + "\n";

        boardToString += "\n";
    }
    
    Board::Board() {
        dices.push_back(die::Die("White"));
        dices.push_back(die::Die("White"));
        dices.push_back(die::Die("Red"));
        dices.push_back(die::Die("Green"));
        dices.push_back(die::Die("Blue"));
        dices.push_back(die::Die("Yellow"));

        rows.push_back(row::Row(2, 1, "Red"));
        rows.push_back(row::Row(2, 1, "Yellow"));
        rows.push_back(row::Row(12, -1, "Green"));
        rows.push_back(row::Row(12, -1, "Blue"));
    }

    Board::~Board() {
    }
    
    void Board::display() {
        updateBoardToString();
        std::cout << boardToString << std::endl;
    }
    
    bool Board::mark(unsigned int index, std::string color) {
        for (unsigned int x = 0; x < rows.size(); x++)
            if (rows.at(x).getColor() == color)
                return rows.at(x).mark(index);

        return false;
    }
    
    void Board::roll() {
        srand(static_cast<unsigned int>(time(0)));
        for (unsigned int x = 0; x < dices.size(); x++)
            dices.at(x).roll();

        updateBoardToString();
    }
}