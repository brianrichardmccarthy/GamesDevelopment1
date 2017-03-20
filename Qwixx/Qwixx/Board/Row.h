#ifndef Row
#include <iostream>
#include <string>
#include <vector>

namespace board {
    namespace row {


        class Row {
            private:
                struct Index {
                    unsigned int m_num;
                    bool m_marked;

                    Index(unsigned int num, bool marked = false) : m_num(num), m_marked(marked) {
                    };
                    inline std::string toString() {
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
            Row();
            Row(unsigned int number, int increase, std::string color);
            ~Row() {
            };
            inline const std::string& toString() {
                return m_rowToString;
            };
            inline const std::string& getColor() {
                return m_color;
            };
            inline const bool& isRowClosed() {
                return m_isClosed;
            }
            bool mark(unsigned int index);
            inline void closeRow() {
                m_isClosed = true;
                updateRowToString();
            };
        };

    }
}

#endif // !Row
