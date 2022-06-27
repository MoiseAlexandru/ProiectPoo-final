
#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <unordered_map>

#include <iostream>
#include <vector>
#include "Pawn.h"
#include "Dice.h"
#include "Cell.h"
#include "PropertyTitleCard.h"
#include "Util.h"
#include "sq.h"

//#include "InfoTemplate.h"
using namespace sq;

class Player {
private:
    int money;
    int freePrisonExits; /// numarul de iesiri gratis de la inchisoare
    int playerId;
    std::string playerName;
    Pawn pawn;
    Dice diceRolls;
    bool eliminated; /// 1-daca jucatorul este eliminat, 0-daca nu
    bool isInPrison; /// 1-daca jucatorul se afla la inchisoare, 0-daca nu
    int getOutOfPrisonTries; /// numarul de aruncari de zar incercand sa iasa de la inchisoare
    std::vector <int> posUtilities; /// pozitiile utilitatilor pe care le detine
    std::vector <int> posTransports; /// pozitiile transporturilor pe care le detine
    std::vector <int> posProperties; /// pozitiile proprietatilor pe care le detine

public:
    int getPlayerId() const {
        return playerId;
    }
    const std::string &getPlayerName() const {
        return playerName;
    }
    Pawn &getPawn() {
        return pawn;
    }
    const std::vector<int> &getPosUtilities() const {
        return posUtilities;
    }
    const std::vector<int> &getPosTransports() const {
        return posTransports;
    }
    const std::vector<int> &getPosProperties() const {
        return posProperties;
    }
    const Dice &getDiceRolls() const {
        return diceRolls;
    }
    bool getEliminated() const {
        return eliminated;
    }
    bool getIsInPrison() const {
        return isInPrison;
    }

    void setEliminated(bool eliminated) {
        Player::eliminated = eliminated;
    }
    void setIsInPrison(bool isInPrison) {
        Player::isInPrison = isInPrison;
    }

    Player() = default;
    Player(std::string name, Pawn pion, int playerid) : money{15'000'000}, freePrisonExits{0}, playerId{playerid}, playerName{name}, pawn{pion}, eliminated{0}, isInPrison{0}, getOutOfPrisonTries{0} {}

    friend std::ostream& operator<<(std::ostream& os, const Player& player)
    {
        os << "Jucatorul are numele " << player.pawn.getPlayerName() << " si joaca cu pionul de culoarea " << player.pawn.getColor() << "\n";
        return os;
    }

    void diceReset() {
        diceRolls.setDie1(1);
        diceRolls.setDie2(1);
        diceRolls.setConsecutiveRolls(0);
    }

    void diceRoll() {
        std::cout << "Scrie 'roll' pentru a arunca cu zarurile\n";
        std::string input;
        std::cin >> input;
        while (input != "roll") {
            std::cout << "Comanda necunoscuta. Incearca din nou.\n";
            std::cin >> input;
        }
        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;
        diceRolls.setDie1(roll1);
        diceRolls.setDie2(roll2);
        std::cout << "Zarurile au fost aruncate. ";
        std::this_thread::sleep_for(1000ms);
        std::cout << roll1 << " si " << roll2 << "\n";
        std::this_thread::sleep_for(1000ms);
        if (roll1 == roll2)
            diceRolls.incrementConsecutiveRolls();
    }

    void newFreeExit() {
        this -> freePrisonExits++;
    }

    void removeMoney(int amount) {
        printColoredText(playerName, this->pawn.getColor());
        printColoredText(" pierde ", "red");
        std::cout << amount << "\n";
        this -> money -= amount;
    }

    void addMoney(int amount) {
        printColoredText(playerName, this->pawn.getColor());
        printColoredText(" castiga ", "green");
        std::cout << amount << "\n";
        this -> money -= amount;
    }

    void collectStart() {
        printColoredText(playerName, this->pawn.getColor());
        std::cout << " trece pe la Start si colecteaza un bonus.\n";
        this -> addMoney(2'000'000);
    }

    int getBalance() {
        return this -> money;
    }

    void displayStatus()
    {
        std::cout << "Nume jucator: ";
        printColoredText(this -> playerName, this->pawn.getColor());
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
            std::cout << squares[it]->getCellName() << ". ";
        std::cout << "\nLinii de transport detinute: ";
        for(auto it : this -> posTransports)
            std::cout << squares[it]->getCellName() << ". ";
        std::cout << "\nUtilitati detinute: ";
        for(auto it : posUtilities)
            std::cout << squares[it]->getCellName() << ". ";
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

        this->pawn.updatePosition(11); /// trimit la inchisoare (pe patratul 11)
        while (1) {
            if (input == "status")
                this->displayStatus();
            if (input == "fullstatus")
                this->displayFullStatus();
            if (input == "free") {
                if (this->freePrisonExits > 0) {
                    std::cout << "Esti liber sa pleci de la tura viitoare.";
                    this->freePrisonExits--;
                    generalMessage();
                    break;
                }
                if (this->freePrisonExits == 0)
                    std::cout << "Nu ai iesiri gratis. Incearca altceva\n";
            }
            if (input == "stay") {
                std::cout << "O sa arunci cu zarul pana putrezesti\n";
                this->isInPrison = 1;
                generalMessage();
                break;
            }
            if (input == "pay") {
                if (this->money >= 500'000) /// daca ai destui bani sa platesti inchisoarea, e ok
                {
                    std::cout << "Ai mituit cu succes paznicii. Esti liber sa pleci de tura viitoare.\n";
                    removeMoney(500'000);
                    generalMessage();
                    break;
                }
                else
                    std::cout << "Esti prea sarac sa iti permiti o mita. Incearca altceva.\n";
            }
            std::cin >> input;

        }
    }

    void generalMessage() {
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

    void buyCell(int buyCost, std::string target) /// costul cumpararii si tipul de celula cumparat
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
                    squares[this -> pawn.getPosition()]->transferOwnership(this -> playerId);
                    if(target == "transport")
                        this -> posTransports.push_back(this -> pawn.getPosition());
                    if(target == "utility")
                        this -> posUtilities.push_back(this -> pawn.getPosition());
                    if(target == "property")
                        this -> posProperties.push_back(this -> pawn.getPosition());
                    std::cout << "Tranzactie realizata cu succes!\n";
                    printColoredText(this -> playerName, this -> pawn.getColor());
                    printColoredText(" pierde ", "red");
                    std::cout << buyCost;
                    std::cout << " dar ";
                    printColoredText("devine proprietar", "green");
                    std::cout << " la " << squares[this -> pawn.getPosition()]->getCellName() << "!\n";
                    this -> generalMessage();
                    return;
                }
                else
                {
                    std::cout << "Nu ai destui bani." << "\n";
                    this -> generalMessage();
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

    void buyLevel()
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
                int pos = this -> pawn.getPosition();
                PropertyTitleCard* prop = dynamic_cast <PropertyTitleCard*>(squares[pos]);

                if(this -> money >= prop->apartmentCost)
                {
                    prop->setConstructionLevel(prop->getConstructionLevel() + 1);
                    this ->removeMoney(prop->apartmentCost);
                    std::cout << " dar ";
                    printColoredText("a facut upgrade la ", "green");
                    std::cout << prop->getCellName() << "\n";
                    squares[pos] = prop;
                    this -> generalMessage();
                    return;
                }
                else
                {
                    std::cout << "Nu ai destui bani pentru upgrade.\n";
                    this -> generalMessage();
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
