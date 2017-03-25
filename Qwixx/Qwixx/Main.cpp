#include "Player\AbstractPlayer.h"
#include "Main.h"

int main(void) {

    instructions();
    
    // game instances
    board::Board board;
    abstractPlayer::AbstractPlayer player("human", &board);
    board.roll();
    std::cout << board << std::endl;

    // Test basic game loop, IO and game state machine
    while (board.getCurrentState() == board.PLAYING) {
        char y;
        std::cin >> y;
        if (y == 'Y' || y == 'y')
            board.endGame();
        else {
            board.update();
            player.mark();
        }
    }

    return 0;
}

void instructions() {
    std::cout << "\tWelcome To Qwixx\n\t----------------\nInstructions Coming Soon!\n" << std::endl;
}