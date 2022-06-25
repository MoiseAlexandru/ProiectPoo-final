
#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <iostream>
#include "Util.h"

class Cell {
private:
    int type;
    int owner = 0;
    int constructionLevel = 0;
    std::string cellName;

public:
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

    int getType() const {
        return type;
    }

    int getOwner() const {
        return owner;
    }

    int getConstructionLevel() const {
        return constructionLevel;
    }

    const std::string &getCellName() const {
        return cellName;
    }

    void setType(int type) {
        Cell::type = type;
    }

    void setOwner(int owner) {
        Cell::owner = owner;
    }

    void setConstructionLevel(int constructionLevel) {
        Cell::owner = constructionLevel;
    }

    void setCellName(const std::string &cellName) {
        Cell::cellName = cellName;
    }


};


#endif //OOP_CELL_H
