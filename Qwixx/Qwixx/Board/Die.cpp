#include "Die.h"

namespace board {
    namespace die {

        void Die::updateDieToString() {
            m_dieToString = m_color + ": " + std::to_string(m_topSide);
        }

        void Die::roll() {
            m_topSide = (rand()%6)+1;
            updateDieToString();
        }
    }
}