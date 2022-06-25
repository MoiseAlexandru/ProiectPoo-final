
#ifndef OOP_UTILITY_H
#define OOP_UTILITY_H

#include <iostream>
#include "Cell.h"

class Utility : public Cell {
public:
    std::string name;
    int amanetCost;
    Utility(std::string name_, int amanetCost_) : name{name_}, amanetCost{amanetCost_} {
        this->setCellName(name_);
        this->setConstructionLevel(0);
        this->setOwner(0);
        this->setType(5);
    }

    Utility() = default;
};


#endif //OOP_UTILITY_H
