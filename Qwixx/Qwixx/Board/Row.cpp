#include "Row.h"

namespace board {
    namespace row {

        Row::Row() {
        }

        void Row::updateRowToString() {
            m_rowToString = m_color + ": ";
            std::vector<Index>::iterator iter;
            for (iter = m_indexes.begin(); iter != m_indexes.end(); ++iter)
                 m_rowToString += iter->toString();
            
            m_rowToString += "Total <" + std::to_string(m_totalMarks) + "> Closed <" + ((m_isClosed) ?  "True" : "False" ) + ">";
        }

        Row::Row(unsigned int number, int increase, std::string color) {
            this->m_color = color;
            m_rowToString = "";
            m_totalMarks = 0;
            for (unsigned int x = 0; number >= 2 && number <= 12; number += increase, x++)
                m_indexes.push_back(Index(number));
            m_isClosed = false;
            m_index = 0;
            updateRowToString();

        }

        bool Row::mark(unsigned int index) {
            if (this->m_index > index) {
                std::cout << "Invalid choice" << std::endl;
                return false;
            }

            if (m_isClosed) {
                std::cout << "Sorry, this row is closed" << std::endl;
                return false;
            }

            this->m_index = index;
            m_indexes.at(index).m_marked = true;
            m_totalMarks++;
            m_isClosed = index == m_indexes.size();
            updateRowToString();
            return true;

        }
    }
}