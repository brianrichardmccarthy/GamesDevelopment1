#include "Die.h"

namespace board {
    namespace die {

        void Die::updateDieToString() {
            dieToString = color + ": " + std::to_string(topSide);
        }

        void Die::roll() {
            srand(static_cast<unsigned int>(time(0)));
            topSide = (rand()%6)+1;
            updateDieToString();
        }
    }
}