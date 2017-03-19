#include "Row.h"

namespace board {
    namespace row {

        void Row::updateRowToString() {
            rowToString = color + ": ";
            // std::vector<Index>::const_iterator iter;
            // for (iter = inventory.begin(); iter != inventory.end(); ++iter)
                // rowToString = rowToString + iter->toString();

            for (unsigned int x = 0; x < inventory.size(); x++)
                rowToString += inventory.at(x).toString();
        }

        Row::Row(unsigned int number, int increase, std::string color) {
            this->color = color;
            rowToString = "";
            totalMarks = 0;
            for (unsigned int x = 0; number >= 2 && number <= 12; number += increase, x++) {
                inventory.push_back(Index(number));

                updateRowToString();
            }
        }
        bool Row::mark(unsigned int index) {
            if (this->index > index)
                return false;

            this->index = index;
            inventory.at(index).marked = true;
            totalMarks++;
            updateRowToString();
            return true;
        }
    }
}