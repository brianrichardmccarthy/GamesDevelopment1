#include "Board\Board.h"

int main(void) {

    /* board::die::Die die("red");
    
    for (int x = 0; x < 100; x++) {
        die.roll();
        std::cout << die.toString() << std::endl;
    } */

    /* board::row::Row rowOne(2, 1, "red");
    board::row::Row rowTwo(12, -1, "yellow");

    std::cout << "" << rowOne.mark(4) << std::endl;
    std::cout << "" << rowOne.mark(2) << std::endl;

    std::cout << rowOne.toString() << std::endl;
    std::cout << rowTwo.toString() << std::endl; */

    board::Board board;

    board.roll();
    board.display();
    
    board.mark(1, "Red");
    board.mark(4, "Red");

    board.mark(2, "Yellow");
    board.mark(5, "Yellow");

    board.mark(8, "Blue");
    board.mark(9, "Blue");

    board.mark(1, "Green");
    board.mark(10, "Green");

    board.roll();
    board.display();

    system("PAUSE");
    return 0;
}