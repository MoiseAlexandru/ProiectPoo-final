
#ifndef OOP_UTIL_H
#define OOP_UTIL_H

#include <Windows.h>
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
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  /// pentru a colora textul din consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    if(color == "red" || color == "rosu")
        SetConsoleTextAttribute(hConsole, 4);
    if(color == "blue" || color == "albastru")
        SetConsoleTextAttribute(hConsole, 1);
    if(color == "yellow" || color == "galben")
        SetConsoleTextAttribute(hConsole, 6);
    if(color == "green" || color == "verde")
        SetConsoleTextAttribute(hConsole, 2);
    if(color == "purple" || color == "mov")
        SetConsoleTextAttribute(hConsole, 5);

    std::cout << text;
    SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}


#endif //OOP_UTIL_H
