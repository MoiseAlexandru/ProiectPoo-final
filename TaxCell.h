#ifndef OOP_TAXCELLS_H
#define OOP_TAXCELLS_H

#include "Cell.h"

class TaxCell : public Cell {
public:
    std::string name;
    int amount;

    TaxCell(std::string name_, int amount_) : name{name_}, amount{amount_ * 1000} {
        this -> cellName = name_;
        this -> constructionLevel = 0;
        this -> owner = 0;
        this -> type = 6;
    }

    TaxCell() = default;
};


#endif //OOP_TAXCELL_H
