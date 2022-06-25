#ifndef OOP_DICE_H
#define OOP_DICE_H

#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

class Dice {
public:
    int die1;
    int die2;
    int consecutiveRolls;

    Dice() {
        die1 = 1;
        die2 = 1;
        consecutiveRolls = 0;
    }

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
};


#endif //OOP_DICE_H
