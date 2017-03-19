#include "Row.h"

namespace board {
    namespace row {

        void Row::updateRowToString() {
            rowToString = color + ": ";
            // std::vector<Index>::const_iterator iter;
            // for (iter = indexes.begin(); iter != indexes.end(); ++iter)
                 // rowToString += (*iter).toString;
            for (unsigned int x = 0; x < indexes.size(); x++)
                rowToString += indexes.at(x).toString();

            rowToString += "Total <" + std::to_string(totalMarks) + ">";
        }

        Row::Row(unsigned int number, int increase, std::string color) {
            this->color = color;
            rowToString = "";
            totalMarks = 0;
            for (unsigned int x = 0; number >= 2 && number <= 12; number += increase, x++) {
                indexes.push_back(Index(number));

                updateRowToString();
            }
            index = 0;
        }
        bool Row::mark(unsigned int index) {
            if (this->index > index) {
                std::cout << "Invalid choice" << std::endl;
                return false;
            }

            this->index = index;
            indexes.at(index).marked = true;
            totalMarks++;
            updateRowToString();
            return true;

        }
    }
}