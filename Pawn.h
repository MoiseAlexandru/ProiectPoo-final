#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include <iostream>

class Pawn {
private:
    int position;
    int player;
    std::string playerName;
    std::string color;

public:
    Pawn() = default;
    Pawn(int player_, const std::string& playerName_, std::string color_) : position{1}, player{player_}, playerName{playerName_}, color{color_} {}

    void updatePosition(int newPosition) {
        this -> position = newPosition;
    }

    int getPlayer() const {
        return player;
    }
    int getPosition() const {
        return position;
    }
    void setPlayer(int player) {
        Pawn::player = player;
    }
    const std::string &getPlayerName() const {
        return playerName;
    }
    void setPlayerName(const std::string &playerName) {
        Pawn::playerName = playerName;
    }
    const std::string &getColor() const {
        return color;
    }
    void setColor(const std::string &color) {
        Pawn::color = color;
    }
};


#endif //OOP_PAWN_H
