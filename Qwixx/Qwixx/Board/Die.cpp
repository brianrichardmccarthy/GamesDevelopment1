#include "Die.h"

namespace board {
    namespace die {

        void Die::updateDieToString() {
            dieToString = color + ": " + std::to_string(topSide);
        }

        void Die::roll() {
            topSide = (rand()%6)+1;
            updateDieToString();
        }
    }
}