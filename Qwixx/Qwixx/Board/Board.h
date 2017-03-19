#ifndef Board
// #pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Die.h"
#include "Row.h"

namespace board {

    class Board {
        public:
        enum GAMESTATES {
            PLAYING,
            DRAW,
            WIN,
            LOSE
        };
        Board();
        ~Board();
        void display();
        bool mark(unsigned int index, std::string color);
        void roll();
        inline const std::string& toString() {
            return boardToString;
        };

        inline const GAMESTATES& getCurrentState() {
            return gamestates;
        };

        private:
        std::vector<die::Die> dices;
        std::vector<row::Row> rows;
        std::string boardToString;
        unsigned int closedRow;
        // closedRow, gamestates
        
        GAMESTATES gamestates;
        
        void updateBoardToString();




    };

}
#endif // !Board
