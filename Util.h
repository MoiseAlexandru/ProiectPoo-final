
#ifndef OOP_UTIL_H
#define OOP_UTIL_H

#include "rlutil.h"
#include <iostream>

inline std::string toWord(int type) {  /// o functie care primeste ca parametrul tipul (int) si imi returneaza semnificatia lui
    std::string output;
    if(type == 0)
        output = "'proprietate'";
    if(type == 1)
        output = "'start'";
    if(type == 2)
        output = "'sansa'";
    if(type == 3)
        output = "'cutia comunitatii'";
    if(type == 4)
        output = "'inchisoare'";
    if(type == 5)
        output = "'utilitati'";
    if(type == 6)
        output = "'taxe'";
    if(type == 7)
        output = "'mergi la inchisoare'";
    if(type == 8)
        output = "'transport'";
    if(type == 9)
        output = "'parcare gratis'";
    return output;
}

inline void printColoredText(std::string text, std::string color) {
    rlutil::saveDefaultColor();
    if(color == "red" || color == "rosu")
        rlutil::setColor(4);
    if(color == "blue" || color == "albastru")
        rlutil::setColor(1);
    if(color == "yellow" || color == "galben")
        rlutil::setColor(14);
    if(color == "green" || color == "verde")
        rlutil::setColor(2);
    if(color == "purple" || color == "mov")
        rlutil::setColor(5);
    std::cout << text;
    rlutil::resetColor();
}

#endif //OOP_UTIL_H
