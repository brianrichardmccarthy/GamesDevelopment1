#ifndef Board
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
            return m_boardToString;
        };

        inline const GAMESTATES& getCurrentState() const {
            return m_gamestates;
        };
        void update();
        void endGame();
    

        private:
        std::vector<die::Die> m_dices;
        std::vector<row::Row> m_rows;
        std::string m_boardToString;
        unsigned int m_closedRow;
        
        GAMESTATES m_gamestates;
        
        void updateBoardToString();
    };

}
#endif // !Board
