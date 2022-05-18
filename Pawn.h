#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include <iostream>

class Pawn {
public:
    int position;
    int player;
    std::string playerName;
    std::string color;
    Pawn() = default;
    Pawn(int player_, const std::string& playerName_, std::string color_) : position{1}, player{player_}, playerName{playerName_}, color{color_} {}

    void updatePosition(int newPosition) {
        this -> position = newPosition;
    }
};


#endif //OOP_PAWN_H
