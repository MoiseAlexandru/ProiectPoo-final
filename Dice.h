#ifndef OOP_DICE_H
#define OOP_DICE_H

#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

class Dice {
private:
    int die1;
    int die2;
    int consecutiveRolls;

public:
    Dice() {
        die1 = 1;
        die2 = 1;
        consecutiveRolls = 0;
    }

    /*
    void diceReset() {
        die1 = 1;
        die2 = 1;
        consecutiveRolls = 0;
    }

    void diceRoll() {
        std::cout << "Scrie 'roll' pentru a arunca cu zarurile\n";
        std::string input;
        std::cin >> input;
        while(input != "roll")
        {
            std::cout << "Comanda necunoscuta. Incearca din nou.\n";
            std::cin >> input;
        }
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        std::cout << "Zarurile au fost aruncate. ";
        std::this_thread::sleep_for(1000ms);
        std::cout << die1 << " si " << die2 << "\n";
        std::this_thread::sleep_for(1000ms);
        if(die1 == die2)
            consecutiveRolls++;
    }
    */
    int getDie1() const {
        return die1;
    }

    int getDie2() const {
        return die2;
    }

    int getConsecutiveRolls() const {
        return consecutiveRolls;
    }

    void setDie1(int die1) {
        this->die1 = die1;
    }

    void setDie2(int die2) {
        this->die2 = die2;
    }

    void setConsecutiveRolls(int consecutiveRolls) {
        this->consecutiveRolls = consecutiveRolls;
    }

    void incrementConsecutiveRolls() {
        this->consecutiveRolls++;
    }
};


#endif //OOP_DICE_H
