#ifndef Row
#include <iostream>
#include <string>
#include <vector>

namespace board {
    namespace row {

        /**
            Class to represent each colored row.
            Tracks if its open or closed,
            How many marks it has,
            and its color.
            As well as other stuff.
        */
        class Row {
            private:
                /**
                    Used to represent each of the 11 numbers,
                    and if they have been marked.
                */
                struct Index {
                    unsigned int m_num;
                    bool m_marked;

                    /**
                        Constructor
                        Parameters
                            unsigned int number between 2 and 12 inclusive
                            bool marked default is false;
                    */
                    Index(unsigned int num, bool marked = false) : m_num(num), m_marked(marked) {
                    };

                    // returns a String representing this index
                    inline std::string toString() const {
                        return "<" + std::to_string(m_num) + ": " + ((m_marked) ? "Y" : "N") + "> ";
                };
            };
            
            std::string m_rowToString;
            std::string m_color;
            std::vector<Index> m_indexes;
            unsigned int m_index;
            unsigned int m_totalMarks;
            void updateRowToString();
            bool m_isClosed;

            public:
            
            /**
                Constructor
                Parameters
                    unsigned int starting number (2 or 12)
                    int increase for starting number (1 or -1)
                    string color of the row
                    unsigned int total marks default value of 0
                    bool is closed default value of false
                    unsigned int index default value of 0
            */
            Row(unsigned int number, int increase, std::string color, unsigned int totalMarks = 0, bool isClosed = false, unsigned int index = 0);

            // destructor
            ~Row() {
            };
            
            /**
                Returns a reference string describing this object state
                Return
                    const string reference
            */
            inline const std::string& toString() const {
                return m_rowToString;
            };

            /**
                Returns a reference to the string color of this row
                Return
                    const string reference to the color of the row
            */
            inline const std::string& getColor() const {
                return m_color;
            };

            /**
                Returns true or false depending on if the row is closed
                Return
                    const bool reference to is closed
            */
            inline const bool& isRowClosed() const {
                return m_isClosed;
            }

            /**
                Closes this row
            */
            inline void closeRow() {
                m_isClosed = true;
                updateRowToString();
            };

            /**
                Gets the current index of vector of struct Index
                Returns
                    const unsigned int reference to index
            */
            inline const unsigned int& getIndex() const {
                return m_index;
            }

            /**
                Marks an Index on the board
                Parameters
                    Index - unsigned int most be greater than or equal to lowest
                    Lowest - unsigned int colored dice + (lowest) white dice
                Returns
                    Bool - has the marked been placed
            */
            bool mark(unsigned int index, unsigned int lowest);

            /* const std::string& operator<<(Row& row) const {
                return m_rowToString;
            } */
        };

    }
}

#endif // !Row
