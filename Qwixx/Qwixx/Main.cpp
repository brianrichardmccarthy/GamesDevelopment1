#include "Board\BoardHeader.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(void) {

    /* board::die::Die die("red");
    
    for (int x = 0; x < 100; x++) {
        die.roll();
        std::cout << die.toString() << std::endl;
    } */

    board::row::Row rowOne(2, 1, "red");
    // board::row::Row rowTwo(12, -1, "yellow");

    std::cout << "" << rowOne.mark(4) << std::endl;
    std::cout << "" << rowOne.mark(2) << std::endl;

    std::cout << rowOne.toString() << std::endl;
    // std::cout << rowTwo.toString() << std::endl;
    
    system("PAUSE");
    return 0;
}