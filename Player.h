
#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <unordered_map>

#include <iostream>
#include <vector>
#include "Pawn.h"
#include "Dices.h"
#include "Cell.h"
#include "PropertyTitleCard.h"
#include "Util.h"

//#include "InfoTemplate.h"
extern std::vector <Cell*> squares;
extern std::unordered_map <std::string, int> playerId; /// zice id-ul (pozitia) jucatorului

class Player {
private:
    int money;
    int freePrisonExits; /// numarul de iesiri gratis de la inchisoare
public:
    std::string playerName;
    Pawn pawn;
    Dices dices;
    bool eliminated; /// 1-daca jucatorul este eliminat, 0-daca nu
    bool isInPrison; /// 1-daca jucatorul se afla la inchisoare, 0-daca nu
    int getOutOfPrisonTries; /// numarul de aruncari de zar incercand sa iasa de la inchisoare
    std::vector <int> posUtilities; /// pozitiile utilitatilor pe care le detine
    std::vector <int> posTransports; /// pozitiile transporturilor pe care le detine
    std::vector <int> posProperties; /// pozitiile proprietatilor pe care le detine

    Player() = default;
    Player(std::string name, Pawn pion) : money{15000000}, freePrisonExits{0}, playerName{name}, pawn{pion}, eliminated{0}, isInPrison{0}, getOutOfPrisonTries{0} {}

    friend std::ostream& operator<<(std::ostream& os, const Player& player)
    {
        os << "Jucatorul are numele " << player.pawn.playerName << " si joaca cu pionul de culoarea " << player.pawn.color << "\n";
        return os;
    }

    void newFreeExit() {
        this -> freePrisonExits++;
    }

    void removeMoney(int amount) {
        printColoredText(playerName, this->pawn.color);
        printColoredText(" pierde ", "red");
        std::cout << amount << "\n";
        this -> money -= amount;
    }

    void addMoney(int amount) {
        printColoredText(playerName, this->pawn.color);
        printColoredText(" castiga ", "green");
        std::cout << amount << "\n";
        this -> money -= amount;
    }

    void collectStart() {
        printColoredText(playerName, this->pawn.color);
        std::cout << " trece pe la Start si colecteaza un bonus.\n";
        this -> addMoney(2000000);
    }

    int getBalance() {
        return this -> money;
    }

    void displayStatus()
    {
        std::cout << "Nume jucator: ";
        printColoredText(this -> playerName, this->pawn.color);
        std::cout << "\n";
        std::cout << "Avere: " << this -> money << "\n";
        std::cout << "In inchisoare? 0-nu, 1-da: " << this -> isInPrison << "\n";
        std::cout << "Numar iesiri gratis: " << this -> freePrisonExits << "\n";
    }

    void displayFullStatus()
    {
        displayStatus();
        std::cout << "Proprietati detinute: ";
        for(auto it : this -> posProperties)
            std::cout << squares[it]->cellName << ". ";
        std::cout << "\nLinii de transport detinute: ";
        for(auto it : this -> posTransports)
            std::cout << squares[it]->cellName << ". ";
        std::cout << "\nUtilitati detinute: ";
        for(auto it : posUtilities)
            std::cout << squares[it]->cellName << ". ";
        std::cout << "\n";
    }

    void sendToPrison() {
        std::cout
                << "Esti trimis la inchisoare. Poti sta la inchisoare ('stay') pana dai o dubla, sa platesti iesirea ('pay') sau sa iti folosesti o iesire gratis daca ai ('free').\n";
        std::cout << "De asemenea, poti vedea statistici despre tine\n";
        std::cout
                << "Scrie 'status' pentru a vedea informatii despre jucator sau 'fullstatus' pentru a vedea informatiile complete";
        std::string input;
        std::cin >> input;
        this->pawn.position = 11; /// trimit la inchisoare (pe patratul 11)
        while (1) {
            if (input == "status")
                this->displayStatus();
            if (input == "fullstatus")
                this->displayFullStatus();
            if (input == "free") {
                if (this->freePrisonExits > 0) {
                    std::cout << "Esti liber sa pleci de la tura viitoare.";
                    this->freePrisonExits--;
                    displayGeneralMessage();
                    break;
                }
                if (this->freePrisonExits == 0)
                    std::cout << "Nu ai iesiri gratis. Incearca altceva\n";
            }
            if (input == "stay") {
                std::cout << "O sa arunci cu zarul pana putrezesti\n";
                this->isInPrison = 1;
                displayGeneralMessage();
                break;
            }
            if (input == "pay") {
                if (this->money >= 500000) /// daca ai destui bani sa platesti inchisoarea, e ok
                {
                    std::cout << "Ai mituit cu succes paznicii. Esti liber sa pleci de tura viitoare.\n";
                    removeMoney(500000);
                    displayGeneralMessage();
                    break;
                }
                else
                    std::cout << "Esti prea sarac sa iti permiti o mita. Incearca altceva.\n";
            }
            std::cin >> input;

        }
    }

    void displayGeneralMessage() {
        std::cout << "Nicio alta actiune posibila.\nScrie 'status' pentru a vedea informatii despre jucator, 'fullstatus' pentru a vedea informatiile complete sau 'end' pentru a termina tura: ";
        std::string action;
        std::cin >> action;
        while (action != "end") {
            if (action == "status") {
                this->displayStatus();
                std::cout
                        << "Scrie 'status' pentru a vedea informatii despre jucator, 'fullstatus'; pentru a vedea informatiile complete sau 'end' pentru a termina tura: ";
            } else if (action == "fullstatus") {
                this->displayFullStatus();
                std::cout << "Scrie 'status' pentru a vedea informatii despre jucator, 'fullstatus'; pentru a vedea informatiile complete sau 'end' pentru a termina tura: ";
            }
            else
                std::cout << "Format input gresit, incearca din nou:\n";
            std::cin >> action;
        }
    }

    void displayBuyMessage(int buyCost, std::string target) /// costul cumpararii si tipul de celula cumparat
    {
        std::cout << "Scrie 'status' pentru a vedea informatii despre jucator, 'fullstatus' pentru informatii complete, 'buy' pentru a cumpara celula sau 'end' pentru a termina tura: ";
        std::string action;
        std::cin >> action;
        while(action != "end")
        {
            if(action == "status" || action == "fullstatus")
            {
                if(action == "status")
                    this -> displayStatus();
                else if(action == "fullstatus")
                    this -> displayFullStatus();
                std::cout << "Scrie 'status' pentru a vedea informatii despre jucator, 'fullstatus' pentru informatii complete, 'buy' pentru a cumpara sau 'end' pentru a termina tura: ";

            }
            else if(action == "buy")
            {
                if(this -> money >= buyCost)
                {
                    this -> money -= buyCost;
                    squares[this -> pawn.position]->transferOwnership(playerId[this -> playerName]);
                    if(target == "transport")
                        this -> posTransports.push_back(this -> pawn.position);
                    if(target == "utility")
                        this -> posUtilities.push_back(this -> pawn.position);
                    if(target == "property")
                        this -> posProperties.push_back(this -> pawn.position);
                    std::cout << "Tranzactie realizata cu succes!\n";
                    printColoredText(this -> playerName, this -> pawn.color);
                    printColoredText(" pierde ", "red");
                    std::cout << buyCost;
                    std::cout << " dar ";
                    printColoredText("devine proprietar", "green");
                    std::cout << " la " << squares[this -> pawn.position]->cellName << "!\n";
                    this -> displayGeneralMessage();
                    return;
                }
                else
                {
                    std::cout << "Nu ai destui bani." << "\n";
                    this -> displayGeneralMessage();
                    return;
                }
            }
            else if(action == "end")
                return;
            else
                std::cout << "Format input gresit, incearca din nou:\n";
            std::cin >> action;
        }
    }

    void displayBuyLevel() /// aici mai trebuie vazut cu nivelele
    {
        std::cout << "Scrie 'status' pentru a vedea informatii despre jucator, 'fullstatus' pentru informatii complete, 'upgrade' pentru a upgrada proprietatea sau 'end' pentru a termina tura: ";
        std::string action;
        std::cin >> action;
        while(action != "end")
        {
            if(action == "status" || action == "fullstatus")
            {
                if(action == "status")
                    this -> displayStatus();
                if(action == "fullstatus")
                    this -> displayFullStatus();
                std::cout << "Scrie 'status' pentru a vedea informatii despre jucator, 'fullstatus' pentru informatii complete, 'upgrade' pentru a cumpara sau 'end' pentru a termina tura: ";
            }
            else if(action == "upgrade")
            {
                int pos = this -> pawn.position;
                PropertyTitleCard* prop = dynamic_cast <PropertyTitleCard*>(squares[pos]);

                if(this -> money >= prop->apartmentCost)
                {
                    prop->constructionLevel++;
                    this ->removeMoney(prop->apartmentCost);
                    std::cout << " dar ";
                    printColoredText("a facut upgrade la ", "green");
                    std::cout << prop->cellName << "\n";
                    squares[pos] = prop;
                    this -> displayGeneralMessage();
                    return;
                }
            }
            else if(action == "end")
                return;
            else
                std::cout << "Format input gresit, incearca din nou:\n";
            std::cin >> action;
        }
    }

};


#endif //OOP_PLAYER_H
