#include "Die.h"

namespace board {
    namespace die {

        void Die::updateDieToString() {
            // if the die is closed set it to an empty string
            // else show the dies' info
            m_dieToString = (m_isClosed) ? "" : m_color + ": " + std::to_string(m_topSide) + ((m_valid) ? " Lowest index <" + std::to_string(m_lowestIndex) + ">" : "");
        }

        void Die::roll() {
            // get a number between 0 < - > 5 and add 1 to it
            // update the string representation of this object
            m_topSide = (rand()%6)+1;
            updateDieToString();
        }
    }
}