
#ifndef OOP_UTIL_H
#define OOP_UTIL_H

#include "rlutil.h"
#include <iostream>

inline std::string toWord(int type) {  /// o functie care primeste ca parametrul tipul (int) si imi returneaza semnificatia lui
    std::string output;
    switch(type) {
        case 1:
            return "'start'";
        case 2:
            return  "'sansa'";
        case 3:
            return "'cutia comunitatii'";
        case 4:
            return "'inchisoare'";
        case 5:
            return "'utilitati'";
        case 6:
            return "'taxe'";
        case 7:
            return "'mergi la inchisoare'";
        case 8:
            return "'transport'";
        case 9:
            return "'parcare gratis'";
        default:
            return "'proprietate'";
    }
}

inline void printColoredText(const std::string &text, const std::string &color) {
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
