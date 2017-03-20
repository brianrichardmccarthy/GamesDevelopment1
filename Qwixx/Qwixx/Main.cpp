#include "Board\Board.h"

enum PLAYERS {
    COMPUTER,
    HUMAN
};

int main(void) {

    board::Board board;
    
    while (board.getCurrentState() == board.PLAYING) {
        board.update();
        char y;
        std::cin >> y;
        if (y == 'Y' || y == 'y')
            board.endGame();
    }

    return 0;
}