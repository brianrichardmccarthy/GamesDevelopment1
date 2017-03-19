// #ifndef Board
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Die.h"
#include "Row.h"

namespace board {

    class Board {
        private:
        std::vector<die::Die> dices;
        std::vector<row::Row> rows;
        std::string boardToString;
        void updateBoardToString();

        public:
        Board();
        ~Board();
        void display();
        bool mark(unsigned int index, std::string color);
        void roll();
        inline const std::string& toString() {
            return boardToString;
        };

    };

}
// #endif // !Board
