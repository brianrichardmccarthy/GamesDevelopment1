#include "Board\Board.h"

enum PLAYERS {
    COMPUTER,
    HUMAN
};

int main(void) {

    board::Board board;

    while (board.getCurrentState() == board.PLAYING) {

    }
    system("PAUSE");
    return 0;
}