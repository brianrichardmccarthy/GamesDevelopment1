#ifndef Board
#include <iostream>
#include <string>
#include <vector>
#include "Die.h"
#include "Row.h"

namespace board {

    /**
        Board class, handles players card, dices, game state etc
    */
    class Board {
        public:
        
        /**
            Marks on each row and what they are worth points wise.
        */
        enum SCORES {
            ONE = 1,
            TWO = 3,
            THREE = 6,
            FOUR = 10,
            FIVE = 15,
            SIX = 21,
            SEVEN = 28,
            EIGHT = 36,
            NINE = 45,
            TEN = 55,
            ELEVEN = 66,
            TWELVE = 72
        };

        /**
            States the game can be in
        */
        enum GAMESTATES {
            PLAYING,
            DRAW,
            WIN,
            LOSE
        };

        // constructor
        Board();
        
        // destructor
        ~Board();
        
        /**
            Displays the board
        */
        void display();
        
        /**
            Attemps to mark at given index on the given row color from the current player
            Parameter
                const unsigned int reference index to place the mark
                const string reference color of the row
                const string reference player whos board the mark is to be place on
            Return
                bool was the move successful
        */
        bool mark(const unsigned int& index, const std::string& color, const std::string& player);
        
        /**
            Rolls any and all dices that are not closed
        */
        void roll();
        
        /**
            Updates and displays the board, more features to come
        */
        void update();
        
        /**
            Changes the game state to another state
            This method will change to Update state or something more appropriate in future iterations of this project
        */
        void endGame();
        
        /**
            Returns this class details represented as a string
            Return
                const string reference
        */
        inline const std::string& toString() const {
            return m_boardToString;
        };

        /**
            Returns the board current game state
            Return
                const GAMESTATE reference
        */
        inline const GAMESTATES& getCurrentState() const {
            return m_gamestates;
        };

        friend std::ostream& operator<<(std::ostream& stream, const Board& board) {
            return stream << board.toString();
        };
    

        private:
        
        /**
            Card has four Row classes {red, yellow, blue, green}
            Default constructor and destructor
        */
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
        bool m_valid[4];

        /**
            updates this boards' string representation
        */
        void updateBoardToString();
    };

}
#endif // !Board
