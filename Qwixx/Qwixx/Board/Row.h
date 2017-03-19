#ifndef Row
// #pragma once
#include <iostream>
#include <string>
#include <vector>

namespace board {
    namespace row {


        class Row {
            private:
                struct Index {
                    unsigned int num;
                    bool marked;

                    Index(unsigned int num, bool marked = false) : num(num), marked(marked) {
                    };
                    inline std::string toString() {
                    return "<" + std::to_string(num) + ": " + ((marked) ? "Y" : "N") + "> ";
                };
            };
            
            std::string rowToString;
            std::string color;
            std::vector<Index> indexes;
            unsigned int index;
            unsigned int totalMarks;
            void updateRowToString();
            

            public:
            Row(unsigned int number, int increase, std::string color);
            ~Row() {
            };
            inline const std::string& toString() {
                return rowToString;
            };
            bool mark(unsigned int index);
            inline const std::string& getColor() {
                return color;
            };
        };

    }
}

#endif // !Row
