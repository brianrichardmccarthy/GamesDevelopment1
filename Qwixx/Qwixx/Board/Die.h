#ifndef Die
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace board {
    namespace die {
        
        /**
            Class to represent the dice. 
            Contains info on the dies' color, its' face up, if its' closed, 
            the number of the colored die plus the lowest white die, valid that does something, a string representing it.
        */
        class Die {
            private:
            std::string m_dieToString;
            std::string m_color;
            unsigned int m_topSide;
            bool m_isClosed = false;
            bool m_valid = true;
            unsigned int m_lowestIndex;
            inline void updateDieToString();

            public:
            
            /**
                Constructor
                Parameter
                    string color of die
            */
            Die(std::string color) : m_color(color) {
            };
            
            // destructor
            ~Die() {
            };

            /**
                Rolls the die and gets a new value for the top face of the die
                a number between 1 < - > 6
            */
            void roll();
            
            /**
                Returns a string reference that show information about this class
                Return
                    const string reference
            */
            inline const std::string& toString() {
                return m_dieToString;
            };

            /**
                close this object if the row with the same color is closed
            */
            inline void closeDie() {
                m_isClosed = true;
                updateDieToString();
            }

            /**
                Returns a bool of is this die is closed
                Return
                    const bool reference
            */
            inline const bool& isClosed() const {
                return m_isClosed;
            };

            /**
                Returns a unsigned int the top face value
                Return
                    const unsigned int reference
            */
            inline const unsigned int& getTop() const {
                return m_topSide;
            };

            /**
                Set the bool valid
                Parameters
                    bool
            */
            inline void setValid(bool valid) {
                m_valid = valid;
            };

            /**
                Set the lowest value to either this face up plus the lowest white die
                or if the color is white the two white dices added together
            */
            inline void setLowest(unsigned int low) {
                m_lowestIndex = low;
                updateDieToString();
            }

            /**
                Gets the lowest (the number of the colored die plus the white or the two white dies added together)
                Return
                    const unsigned int reference
            */
            inline const unsigned  int& getLowest() const {
                return m_lowestIndex;
            }
        };
    }
}

#endif // !Die
