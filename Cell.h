
#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <iostream>
#include "Util.h"

class Cell {
public:
    int type;
    int owner = 0;
    int constructionLevel = 0;
    std::string cellName;

    void transferOwnership(int newOwner) {
        this -> owner = newOwner;
    }

    Cell(int type_, std::string name) : type{type_}, owner{0}, constructionLevel{0}, cellName{name} {
        owner = 0;
    }
    Cell() = default;
    virtual  ~Cell() = default;

    friend std::ostream& operator<<(std::ostream& os, const Cell& cell)
    {
        os << "Tipul " << toWord(cell.type) << " cu numele '" << cell.cellName << "'\n";
        return os;
    }

};


#endif //OOP_CELL_H
