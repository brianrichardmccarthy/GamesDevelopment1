// #ifndef Die
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace board {
    namespace die {
        class Die {
            private:
            std::string dieToString;
            std::string color;
            int topSide;
            inline void updateDieToString();

            public:
            Die(std::string color) : color(color) {
            };
            ~Die() {
            };
            void roll();
            inline const std::string& toString() {
                return dieToString;
            };


        };
    }
}

// #endif // !Die
