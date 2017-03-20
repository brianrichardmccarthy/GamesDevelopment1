#ifndef Die
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace board {
    namespace die {
        class Die {
            private:
            std::string m_dieToString;
            std::string m_color;
            int m_topSide;
            inline void updateDieToString();

            public:
            Die(std::string color) : m_color(color) {
            };
            ~Die() {
            };
            void roll();
            inline const std::string& toString() {
                return m_dieToString;
            };


        };
    }
}

#endif // !Die
