
#ifndef OOP_TRANSPORT_H
#define OOP_TRANSPORT_H

#include <iostream>
#include <array>
#include "Cell.h"

const int maxTransports = 5;
class Transport : public Cell {
private:
    std::string name;
    int buyCost;
    std::array <int, 5> rentCosts; /// costurile chiriei daca jucatorul detine 1 / 2 / 3 / 4 statii de transport
    int amanetCost;
public:
    int getBuyCost() const {
        return buyCost;
    }

    Transport(std::string name_, int cost1, int cost2, int cost3, int cost4, int amanetCost_) :
    name{name_}, buyCost{2'000'000}, rentCosts{0, cost1 * 1000, cost2 * 1000, cost3 * 1000, cost4 * 1000}, amanetCost{amanetCost_ * 1000} {
        this->setCellName(name_);
        this->setOwner(0);
        this->setConstructionLevel(0);
        this->setType(8);
    }

    Transport() = default;
};


#endif //OOP_TRANSPORT_H
