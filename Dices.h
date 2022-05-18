#ifndef OOP_DICES_H
#define OOP_DICES_H

#include <iostream>
#include <Windows.h>

class Dices {
public:
    int dice1;
    int dice2;
    int consecutiveRolls;

    Dices() {
        dice1 = 1;
        dice2 = 1;
        consecutiveRolls = 0;
    }

    void diceReset() {
        dice1 = 1;
        dice2 = 1;
        consecutiveRolls = 0;
    }

    void diceRoll() {
        std::cout << "Scrie 'roll' pentru a arunca cu zarurile\n";
        std::string input;
        std::cin >> input;
        while(input != "roll")
        {
            std::cout << "Unknown command. Try again.\n";
            std::cin >> input;
        }
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        std::cout << "Zarurile au fost aruncate. ";
        Sleep(1000);
        std::cout << dice1 << " si " << dice2 << "\n";
        Sleep(1000);
        if(dice1 == dice2)
            consecutiveRolls++;
        if(consecutiveRolls == 3)
            std::cout << "Prea mult noroc. Mergi la inchisoare!\n";
    }
};


#endif //OOP_DICES_H
