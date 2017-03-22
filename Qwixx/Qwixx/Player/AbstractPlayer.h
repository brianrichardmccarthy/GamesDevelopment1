#ifndef AbstractPlayer
#include <iostream>
#include <string>

#include "../Board/Board.h"

namespace abstractPlayer {

    /**
        Base player class
    */
    class AbstractPlayer {
        public:
        /**
            Constructor
                Parameters:
                    Name (string)
                    board (Board*)
        */
        AbstractPlayer(std::string name, board::Board* board) : m_name(name), m_board(board) {
        };

        /**
            Destructor
        */
        ~AbstractPlayer();
        
        /**
            mark the board.
            if player is human, get user input
        */
        void mark();

        protected:
        std::string m_name;
        board::Board* m_board;
    };
}


#endif // !AbstractPlayer
