#include "Row.h"

namespace board {
    namespace row {

        void Row::updateRowToString() {
            m_rowToString = m_color + ": ";

            // loop throught the indexes and get their toString and add it this rows' toString
            std::vector<Index>::iterator iter;
            for (iter = m_indexes.begin(); iter != m_indexes.end(); ++iter)
                 m_rowToString += iter->toString();
            
            // add total marks and if its closed
            m_rowToString += "Total <" + std::to_string(m_totalMarks) + "> Closed <" + ((m_isClosed) ?  "True" : "False" ) + ">";
        }

        Row::Row(unsigned int number, int increase, std::string color, unsigned int totalMarks, bool isClosed, unsigned int index)
        : m_color(color), m_totalMarks(totalMarks), m_isClosed(isClosed), m_index(index) {

            // create the indexes
            for (unsigned int x = 0; number >= 2 && number <= 12; number += increase, x++)
                m_indexes.push_back(Index(number));
            
            updateRowToString();
        }

        bool Row::mark(unsigned int index, unsigned int lowest) {
            
            // prevent updates on invalid index
            // invalid if
                // index is less than m_index
                // or index is greater than or equal to 11
                // or index is lower than lowest
            if (this->m_index > index || index >= m_indexes.size() || index < lowest) {
                std::cout << "Invalid choice" << std::endl;
                return false;
            }


            // prevent updates on this row if it's closed
            if (m_isClosed) {
                std::cout << "Sorry, this row is closed" << std::endl;
                return false;
            }

            // update this index
            this->m_index = index;
            
            // increase the number of marks in this row
            m_totalMarks++;

            // check if this move will close this row
            m_isClosed = index == (m_indexes.size()-1);
            
            // update Index at index
            m_indexes.at(index).m_marked = true;
            
            // update to string
            updateRowToString();
            
            return true;

        }
    }
}