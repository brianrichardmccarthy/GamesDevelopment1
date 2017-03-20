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
        bool mark(unsigned int index, std::string color, std::string player);
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
        struct Card {
            std::vector<row::Row> m_rows;
            const static unsigned int ROWS = 4;

            Card();
            ~Card();

        };
        std::vector<die::Die> m_dices;
        std::string m_boardToString;
        unsigned int m_closedRow;
        GAMESTATES m_gamestates;
        Card humanPlayer;
        Card computerPlayer;

        void updateBoardToString();
    };

}
#endif // !Board
