#include "AbstractPlayer.h"

namespace abstractPlayer {

    void AbstractPlayer::mark() {
        
        if (m_name == "human") {
            // get user input
            // basic input and output

            int x = 0;
            while (x < 2) {

                bool update = false;
                std::string color;
                std::cout << "Enter color: {Red, Yellow, Green, Blue or None} ";
                std::cin >> color;

                if (tolower(color[0]) == 'r' || tolower(color[0]) == 'y' || tolower(color[0]) == 'g' || tolower(color[0]) == 'b') {
                    color[0] = toupper(color[0]);
                    unsigned int pos;
                    std::cout << "\nEnter a number: ";
                    std::cin >> pos;
                    std::cout << std::endl;
                    update = m_board->mark(pos, color, m_name);
                } else if (tolower(color[0]) == 'n') update = true;

                // only update to get second choice, if first is valid
                // as well as update if the second choice is valid
                if (update) x++;
            }

        }
    
    }
    AbstractPlayer::~AbstractPlayer() {
    }
    
}