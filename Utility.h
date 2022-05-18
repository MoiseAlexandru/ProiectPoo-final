
#ifndef OOP_UTILITY_H
#define OOP_UTILITY_H

#include <iostream>
#include "Cell.h"

class Utility : public Cell {
public:
    std::string name;
    int amanetCost;
    Utility(std::string name_, int amanetCost_) : name{name_}, amanetCost{amanetCost_} {
        this->cellName = name_;
        this->constructionLevel = 0;
        this->owner = 0;
        this->type = 5;
    }

    Utility() = default;
};


#endif //OOP_UTILITY_H
