
#ifndef OOP_PROPERTYTITLECARD_H
#define OOP_PROPERTYTITLECARD_H

#include <iostream>
#include <array>
#include "Cell.h"

const int apartmentLevels = 5;

class PropertyTitleCard : public Cell {
private:
    std::string name;
    int color; /// culoarea setului din care face parte
    int placeRentCost;
    std::array <int, apartmentLevels> rentApartmentCosts;
    int rentHotelCost;
    int apartmentCost;
    int hotelCost;
    int amanetCost; /// nu gasesc traducere la amanet in engleza

public:
    int getPlaceRentCost() const {
        return placeRentCost;
    }
    const std::array<int, apartmentLevels> &getRentApartmentCosts() const {
        return rentApartmentCosts;
    }
    int getApartmentCost() const {
        return apartmentCost;
    }
    int getRentHotelCost() const {
        return rentHotelCost;
    }
    int getAmanetCost() const {
        return  amanetCost;
    }

    PropertyTitleCard(std::string name_, int color_, int placeRentCost_, int a1, int a2, int a3, int a4, int hotelRent, int apartmentCost_, int hotelCost_, int amanetCost_) :
    name{name_}, color{color_}, placeRentCost{placeRentCost_ * 1000}, rentApartmentCosts{0, a1 * 1000, a2 * 1000, a3 * 1000, a4 * 1000},
    rentHotelCost{hotelRent}, apartmentCost{apartmentCost_ * 1000}, hotelCost{hotelCost_ * 1000}, amanetCost{amanetCost_ * 2000} {
        this->setCellName(name_);
        this->setOwner(0);
        this->setType(0);
        this->setConstructionLevel(0);
    };
    /*
    PropertyTitleCard(std::string name, int color, int placeRentCost, int a1, int a2, int a3, int a4, int hotelRent, int apartmentCost, int hotelCost, int amanetCost)
    {
        this -> color = color;
        this -> name = name;
        this -> placeRentCost = placeRentCost * 1000;
        this -> rentApartmentCosts[1] = a1 * 1000;
        this -> rentApartmentCosts[2] = a2 * 1000;
        this -> rentApartmentCosts[3] = a3 * 1000;
        this -> rentApartmentCosts[4] = a4 * 1000;
        this -> rentHotelCost = hotelRent * 1000;
        this -> hotelCost = hotelCost * 1000;
        this -> apartmentCost = apartmentCost * 1000;
        this -> amanetCost = amanetCost * 2000;
    }
    */
    PropertyTitleCard() = default;

    friend std::ostream& operator<<(std::ostream&os, const PropertyTitleCard& card)
    {
        os << "Titlu de proprietate.\nNume: " << card.name << "\n" << "Costuri inchiriere apartamente:\n";
        for(int i = 1; i <= 4; i++)
            os << i << ". " << card.rentApartmentCosts[i] << "\n";
        os << "Cost inchiriere hotel: " << card.rentHotelCost << "\n" << "Cost apartament: " << card.apartmentCost << "\n";
        os << "Cost hotel: " << card.hotelCost << "\n" << "Cost amanet: " << card.amanetCost << "\n";
        return os;
    }
    /*
    void update(std::string name, int color, int placeRentCost, int a1, int a2, int a3, int a4, int hotelRent, int apartmentCost, int hotelCost, int amanetCost)
    {
        this -> color = color;
        this -> name = name;
        this -> placeRentCost = placeRentCost;
        this -> rentApartmentCosts[1] = a1 * 1000;
        this -> rentApartmentCosts[2] = a2 * 1000;
        this -> rentApartmentCosts[3] = a3 * 1000;
        this -> rentApartmentCosts[4] = a4 * 1000;
        this -> rentHotelCost = hotelRent * 1000;
        this -> hotelCost = hotelCost * 1000;
        this -> apartmentCost = apartmentCost * 1000;
        this -> amanetCost = amanetCost * 2000;
    }
     */
};


#endif //OOP_PROPERTYTITLECARD_H
