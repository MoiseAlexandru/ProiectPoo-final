#ifndef OOP_TAXCELLS_H
#define OOP_TAXCELLS_H

#include "Cell.h"

class TaxCell : public Cell {
public:
    std::string name;
    int amount;

    TaxCell(std::string name_, int amount_) : name{name_}, amount{amount_ * 1000} {
        this->setCellName(name_);
        this->setConstructionLevel(0);
        this->setOwner(0);
        this->setType(6);
    }

    TaxCell() = default;
};


#endif //OOP_TAXCELL_H
