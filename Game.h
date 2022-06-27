#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <unordered_map>
#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <thread>
#include <ctime>
#include <set>
#include <array>
#include "Pawn.h"
#include "Cell.h"
#include "PropertyTitleCard.h"
#include "TaxCell.h"
#include "Transport.h"
#include "Utility.h"
#include "Player.h"
#include "Util.h"
#include "sq.h"

using namespace sq;

class Game {

    Player players[20];
    int numberOfPlayers = 0;

    int getCellType(Cell *cell) {
        if (dynamic_cast <PropertyTitleCard *> (cell))
            return 0;
        if (dynamic_cast <TaxCell *> (cell))
            return 6;
        if (dynamic_cast <Utility *> (cell))
            return 5;
        if (dynamic_cast <Transport *> (cell))
            return 8;
        return cell->getType();
    }

    void insertCardsData() {

        squares.push_back(new Cell());
        squares.push_back(new Cell(1, "Start"));
        squares.push_back(
                new PropertyTitleCard("Universitatea nationala de aparare", 1, 20, 100, 300, 900, 1600, 2500, 500, 500,
                                      300));
        squares.push_back(new Cell(3, "Cutia comunitatii"));
        squares.push_back(
                new PropertyTitleCard("Muzeul taranului roman", 1, 40, 200, 600, 1800, 3200, 4500, 500, 500, 300));
        squares.push_back(new TaxCell("Impozit profit", 2000));
        squares.push_back(new Transport("Gara de nord", 250, 500, 1000, 2000, 1000));
        squares.push_back(
                new PropertyTitleCard("Institutul geologic", 2, 60, 300, 900, 2700, 4000, 5500, 500, 500, 500));
        squares.push_back(new Cell(2, "Sansa"));
        squares.push_back(
                new PropertyTitleCard("Muzeul de istorie naturala Antipa", 2, 60, 300, 900, 2700, 4000, 5500, 500, 500,
                                      500));
        squares.push_back(new PropertyTitleCard("Opera nationala", 2, 80, 400, 1000, 3000, 4500, 6000, 500, 500, 600));
        squares.push_back(new Cell(4, "Inchisoare"));
        squares.push_back(
                new PropertyTitleCard("Piata Kogalniceanu", 3, 100, 500, 1500, 4500, 6250, 7500, 1000, 1000, 700));
        squares.push_back(new Utility("Uzina electrica", 750));
        squares.push_back(new PropertyTitleCard("Universitatea", 3, 100, 500, 1500, 4500, 6250, 7500, 1000, 1000, 700));
        squares.push_back(
                new PropertyTitleCard("Cercul militar national", 3, 120, 600, 1800, 5000, 7000, 9000, 1000, 1000, 800));
        squares.push_back(new Transport("Aeroportul Henri Coanda", 250, 500, 1000, 2000, 1000));
        squares.push_back(
                new PropertyTitleCard("Casa presei libere", 4, 140, 700, 2000, 5500, 7500, 9500, 1000, 1000, 900));
        squares.push_back(new Cell(3, "Cutia comunitatii"));
        squares.push_back(
                new PropertyTitleCard("Biblioteca universitara", 4, 140, 700, 2000, 5500, 7500, 9500, 1000, 1000, 900));
        squares.push_back(
                new PropertyTitleCard("Parcul cismigiu", 4, 160, 800, 2200, 6000, 8000, 10000, 1000, 1000, 1000));
        squares.push_back(new Cell(9, "Parcare gratuita"));
        squares.push_back(
                new PropertyTitleCard("Muzeul de istorie", 5, 180, 900, 2500, 7000, 8750, 10500, 1500, 1500, 1100));
        squares.push_back(new Cell(2, "Sansa"));
        squares.push_back(
                new PropertyTitleCard("Muzeul George Enescu", 5, 180, 900, 2500, 7000, 8750, 10500, 1500, 1500, 1100));
        squares.push_back(
                new PropertyTitleCard("Muzeul de arta", 5, 200, 1000, 3000, 7500, 9250, 11000, 1500, 1500, 1200));
        squares.push_back(new Transport("Gara Basarab", 250, 500, 1000, 2000, 1000));
        squares.push_back(
                new PropertyTitleCard("Arcul de triumf", 6, 220, 1100, 3300, 8000, 9750, 11500, 1500, 1500, 1300));
        squares.push_back(
                new PropertyTitleCard("Banca nationala", 6, 220, 1100, 3300, 8000, 9750, 11500, 1500, 1500, 1300));
        squares.push_back(new Utility("Uzina de apa", 750));
        squares.push_back(
                new PropertyTitleCard("Tribunalul", 6, 240, 1200, 3600, 8500, 10250, 12000, 1500, 1500, 1400));
        squares.push_back(new Cell(7, "Mergi la inchisoare"));
        squares.push_back(
                new PropertyTitleCard("Ateneul roman", 7, 260, 1300, 3900, 9000, 11000, 12750, 2000, 2000, 1500));
        squares.push_back(
                new PropertyTitleCard("Piata unirii", 7, 260, 1300, 3900, 9000, 11000, 12750, 2000, 2000, 1500));
        squares.push_back(new Cell(3, "Cutia comunitatii"));
        squares.push_back(
                new PropertyTitleCard("Teatrul national", 7, 280, 1500, 4500, 10000, 12000, 14000, 2000, 2000, 1600));
        squares.push_back(new Transport("Aeroportul Baneasa", 250, 500, 1000, 2000, 1000));
        squares.push_back(new Cell(2, "Sansa"));
        squares.push_back(
                new PropertyTitleCard("Cladirea CEC", 8, 350, 1750, 5000, 11000, 13000, 15000, 2000, 2000, 1750));
        squares.push_back(new TaxCell("Taxa de lux", 1000));
        squares.push_back(
                new PropertyTitleCard("Casa poporului", 8, 500, 2000, 6000, 14000, 17000, 20000, 2000, 2000, 2000));
    }


    void readNumberOfPlayers() {
        const int minNumberOfPlayers = 2;
        const int maxNumberOfPlayers = 4;
        bool goodInput = false;
        while (goodInput == false) {
            numberOfPlayers = 0;
            goodInput = true;
            std::cout << "Introdu numarul de jucatori (" << minNumberOfPlayers << "-" << maxNumberOfPlayers << "):";
            std::string s;
            getline(std::cin, s);
            try {
                numberOfPlayers = std::stoi(s);
            }
            catch (std::exception &err) {
                goodInput = false;
                std::cout << "Format input incorect: " << err.what() << "\nIncearca din nou.\n";
            }
            if (goodInput == false)
                continue;
            if (numberOfPlayers < minNumberOfPlayers || numberOfPlayers > maxNumberOfPlayers) {
                std::cout << "Ar trebui sa fie intre " << minNumberOfPlayers << " si " << maxNumberOfPlayers
                          << " jucatori. Incearca din nou.\n\n";
                goodInput = false;
            }
        }
        std::cout << "Acum jucatorii!\n";
    };


    void readPlayers() {
        std::set<std::string> remainingColors;
        bool goodInput = false;
        while (goodInput == false) {
            goodInput = true;
            remainingColors.clear();
            remainingColors.insert({"rosu", "albastru", "galben", "mov", "verde"});
            std::vector<std::string> playerNames;
            std::vector<std::string> playerColors;
            std::cout << "Introdu numele jucatorilor (separare prin spatiu sau linie noua): \n";
            for (int i = 1; i <= numberOfPlayers; i++) {
                std::string name;
                std::cin >> name;
                playerNames.push_back(name);
            }

            std::cout
                    << "Acum introdu culorile pionilor. Din nou, separare prin spatiu sau linie noua.\nPoti alege dintre: \n";
            printColoredText("1. Rosu\n", "red");
            printColoredText("2. Albastru\n", "blue");
            printColoredText("3. Galben\n", "yellow");
            printColoredText("4. Mov\n", "purple");
            printColoredText("5. Verde\n", "green");

            for (int i = 1; i <= numberOfPlayers; i++) {
                std::string color;
                std::cin >> color;
                if (remainingColors.find(color) == remainingColors.end()) {
                    goodInput = false;
                }
                auto posDelete = remainingColors.find(color);
                if (posDelete != remainingColors.end())
                    remainingColors.erase(posDelete);
                playerColors.push_back(color);
            }

            for (int i = 0; i < numberOfPlayers; i++) {
                Pawn pawn(i + 1, playerNames[i], playerColors[i]);
                Player currentPlayer(playerNames[i], pawn, i + 1);
                players[i + 1] = currentPlayer;
            }
            if (goodInput == false) {
                std::cout << "S-a produs o eroare. Refaceti.\n\n";
                continue;
            }

            for (int i = 1; i <= numberOfPlayers; i++) {
                std::cout << players[i].getPlayerName() << " va juca cu pionul ";
                printColoredText(players[i].getPawn().getColor(), players[i].getPawn().getColor());
                std::cout << "!\n";
            }
            std::cout << "\nEste corect? Scrieti 'da' sau 'nu':\n";
            std::string answer;
            std::cin >> answer;
            if (answer == "nu") {
                goodInput = false;
            }
        }
        std::cout << "Continuam...\n\n";
        for (int i = 1; i <= numberOfPlayers; i++)
            std::cout << players[i] << "\n";
    }

    void transferMoneyTo(Player &player, Player &otherPlayer, int amount) {
        player.removeMoney(amount);
        otherPlayer.addMoney(amount);
    }

    bool payUtilityTo(Player &player, int cellOwner) {
        int numUtilities = players[cellOwner].getPosUtilities().size();
        int amountNeeded = 0;
        int dicesSum = player.getDiceRolls().getDie1() + player.getDiceRolls().getDie2();
        if (numUtilities == 1)
            amountNeeded = 4 * 10'000 * dicesSum;
        else if (numUtilities == 2)
            amountNeeded = 10 * 10'000 * dicesSum;
        if (player.getBalance() >= amountNeeded) {
            //transferMoneyTo(cellOwner, amountNeeded);
            transferMoneyTo(player, players[cellOwner], amountNeeded);
            return 1;
        }
        return 0;
    }

    bool payTax(Player &player) {
        int pos = player.getPawn().getPosition();
        TaxCell *tax = dynamic_cast <TaxCell *>(squares[pos]);
        if (player.getBalance() >= tax->amount) {
            player.removeMoney(tax->amount);
            return 1;
        }
        return 0;
    }

    bool payTransportTo(Player &player, int cellOwner) {
        int pos = player.getPawn().getPosition();
        Transport *tr = dynamic_cast <Transport *>(squares[pos]);
        int numTransports = players[cellOwner].getPosTransports().size();
        int amountNeeded = tr->buyCost * numTransports;
        if (player.getBalance() >= amountNeeded) {
            transferMoneyTo(player, players[cellOwner], amountNeeded);
            return 1;
        }
        return 0;
    }

    bool payPropertyRent(Player &player, int cellOwner) {
        int pos = player.getPawn().getPosition();
        int amountNeeded = 0;
        PropertyTitleCard *prop = dynamic_cast <PropertyTitleCard *> (squares[pos]);
        if (prop->getConstructionLevel() == 0)
            amountNeeded = prop->placeRentCost;
        else if (prop->getConstructionLevel() >= 1 && prop->getConstructionLevel() <= 4)
            amountNeeded = prop->rentApartmentCosts[prop->getConstructionLevel()];
        else if (prop->getConstructionLevel() == 5)
            amountNeeded = prop->rentHotelCost;
        if (player.getBalance() >= amountNeeded) {
            transferMoneyTo(player, players[cellOwner], amountNeeded);
            return 1;
        }
        return 0;
    }

    void alternateCommunityChance(Player &player) {
        int reward = rand() % 7 - 2; /// numere de la -2 la +4
        /// daca rewardul este = 0, primeste un free exit
        /// daca nu, primeste / plateste reward * 1mil dolari
        if (reward == 0) {
            std::cout << "Ai castigat o iesire gratis din inchisoare!\n";
            player.newFreeExit();
        } else if (reward > 0) {
            std::cout << "Ai noroc azi. Ai primit un cadou.\n";
            player.addMoney(reward * 1'000'000);
        } else {
            std::cout << "Teapa\n";
            player.removeMoney(-reward * 1'000'000);
        }
    }


    void actions(Player &player) {

        int pos = player.getPawn().getPosition();
        if (squares[pos]->getType() == 1)  /// Celula de tip start
        {
            std::cout << "Ai ajuns pe 'Start', nu se intampla nimic.\n";
            player.generalMessage();
            return;
        }
        if (squares[pos]->getType() == 2)  /// Celula de tip sansa
        {
            std::cout << "Ai ajuns pe o 'Sansa'. Vei avea noroc?\n";
            std::this_thread::sleep_for(1000ms);
            alternateCommunityChance(player);
            player.generalMessage();
            return;
        }
        if (squares[pos]->getType() == 3)  /// Celula de tip cutia comunitatii
        {
            std::cout << "Ai ajuns pe o 'Cutia comunitatii'. Vei avea noroc?\n";
            std::this_thread::sleep_for(1000ms);
            alternateCommunityChance(player);
            player.generalMessage();
            return;
        }
        if (squares[pos]->getType() == 4)  /// Celula de tip inchisoare
        {
            std::cout << "Ai ajuns in vizita la inchisoare, nu se intampla nimic\n";
            player.generalMessage();
            return;
        }
        if (squares[pos]->getType() == 5)  /// Celula de tip utilitate
        {
            std::cout << "Ai ajuns pe o utilitate.\n";

            if (squares[pos]->getOwner() == player.getPlayerId()) /// nu trebuie platit nimic
            {
                std::cout << "Aceasta utilitate este detinuta de tine, nu trebuie sa platesti nimic\n";
                player.generalMessage();
                return;
            } else if (squares[pos]->getOwner() == 0) /// daca este libera, ai posibilitatea de a cumpara
            {
                std::cout
                        << "Aceasta celula nu este detinuta de nimeni, asa ca nu trebuie sa platesti nimic. In schimb o poti cumpara, daca ai destui bani\n";
                player.buyCell(1'500'000, "utility");
                return;
            } else /// trebuie sa platesti celui care detine utilitatea
            {
                int cellOwner = squares[pos]->getOwner();
                std::cout << "Aceasta celula este detinuta de ";
                printColoredText(players[cellOwner].getPlayerName(), players[cellOwner].getPawn().getColor());
                std::cout << "; va trebui sa platesti.";
                bool successfulPay = payUtilityTo(player, squares[pos]->getOwner());
                if (successfulPay == false) {
                    std::cout << "Nu ai destui bani, esti casually eliminat din joc.\n";
                    player.setEliminated(true);
                    return;
                }
                player.generalMessage();
            }
        }
        if (squares[pos]->getType() == 6) /// Celula de tip taxa
        {
            std::cout << "Aceasta celula este de tip taxa, asa ca va trebui sa platesti\n";
            bool successfullPay = payTax(player);
            if (successfullPay == false) {
                std::cout << "Nu ai destui bani, esti casually eliminat din joc.\n";
                player.setEliminated(true);
                return;
            }
            player.generalMessage();
        }
        if (squares[pos]->getType() == 7) /// Celula de tip mergi la inchisoare
            player.sendToPrison();
        if (squares[pos]->getType() == 8) /// Celula de tip transport
        {
            Transport *tr = dynamic_cast <Transport *>(squares[pos]);
            std::cout << "Ai ajuns pe o linie de transport\n";
            if (tr->getOwner() == player.getPlayerId()) /// daca celula iti apartine
            {
                std::cout << "Linia aceasta este detinuta de tine.\n";
                player.generalMessage();
                return;
            } else if (tr->getOwner() == 0) {
                std::cout << "Linia aceasta nu este detinuta de nimeni, dar o poti cumpara\n";
                player.buyCell(tr->buyCost, "transport");
                return;
            } else if (tr->getOwner() != player.getPlayerId()) /// daca celula apartine altcuiva
            {
                int cellOwner = tr->getOwner();
                std::cout << "Aceasta linie de transport este detinuta de ";
                printColoredText(players[cellOwner].getPlayerName(), players[cellOwner].getPawn().getColor());
                std::cout << "; va trebui sa platesti.\n";
                bool successfullPay = payTransportTo(player, cellOwner);
                if (successfullPay == false) {
                    std::cout << "Nu ai destui bani, esti eliminat din joc.\n";
                    player.setEliminated(true);
                    return;
                }
                player.generalMessage();
            }
        }
        if (squares[pos]->getType() == 9) {
            std::cout << "Ai picat pe locul 'parcare gratis'. Nu se intampla nimic\n";
            player.generalMessage();
        }
        if (squares[pos]->getType() == 0) {
            std::cout << "Ai picat pe o proprietate.\n";
            PropertyTitleCard *prop = dynamic_cast <PropertyTitleCard *> (squares[pos]);
            if (squares[pos]->getOwner() == player.getPlayerId()) /// ai picat pe o proprietate pe care o detii
            {
                std::cout << "Proprietatea este detinuta de tine.\n";
                if (prop->getConstructionLevel() == 5) /// e hotel, nu mai poti face nimic
                {
                    player.generalMessage();
                    return;
                }
                if (prop->getConstructionLevel() <= 3) /// se mai poate construi un apartament
                {
                    player.buyLevel();
                    return;
                }
                if (prop->getConstructionLevel() == 4) /// are deja 4 apartamente, putem upgrada la hotel
                {
                    player.buyLevel();
                    return;
                }
            } else if (prop->getOwner() == 0) /// proprietatea nu are owner, atunci poti cumpara
            {
                std::cout << "Proprietatea nu este detinuta de nimeni, dar o poti cumpara.\n";
                player.buyCell(prop->amanetCost, "property");
                return;
            } else if (prop->getOwner() != player.getPlayerId()) /// esti pe o proprietate straina
            {
                std::cout << "Proprietatea este detinuta de ";
                int cellOwner = prop->getOwner();
                printColoredText(players[cellOwner].getPlayerName(), players[cellOwner].getPawn().getColor());
                std::cout << ". Trebuie sa platesti chirie\n";
                bool successfullPay = payPropertyRent(player, cellOwner);
                if (successfullPay == 1) {
                    player.generalMessage();
                    return;
                } else {
                    std::cout << "Nu ai destui bani, esti eliminat din joc.\n";
                    player.setEliminated(true);
                    return;
                }
            }
        }
    }

    void playerTurn(Player &player) {
        int newPosition = player.getPawn().getPosition() + player.getDiceRolls().getDie1() + player.getDiceRolls().getDie2();
        if (newPosition > 40) /// tabla are 40 de celule, daca trece de 40 o ia de la capat (si trece pe la start)
        {
            newPosition = newPosition - 40;
            player.collectStart();
        }
        player.getPawn().updatePosition(newPosition);
        std::cout << "Jucatorul ";
        printColoredText(player.getPlayerName(), player.getPawn().getColor());
        std::cout << " ajunge pe pozitia " << newPosition << ", care este:\n";

        std::cout << squares[newPosition]->getCellName() << "\n";
        std::this_thread::sleep_for(1000ms);
        actions(player);
    }

    void turn() {
        for (int i = 1; i <= numberOfPlayers; i++) {
            if (players[i].getEliminated() == 1)
                continue;
            std::cout << "Jucatorul " << i << " (";
            printColoredText(players[i].getPlayerName(), players[i].getPawn().getColor());
            std::cout << ") " << " la mutare.\n";
            players[i].diceReset(); /// incepe tura, se reseteaza zarurile
            players[i].diceRoll();

            if (players[i].getIsInPrison() == 1) {
                if (players[i].getDiceRolls().getDie1() == players[i].getDiceRolls().getDie2()) {
                    std::cout << "Ai dat dubla! Ai scapat de la inchisoare. Poti muta incepand de la tura viitoare.";
                    players[i].setIsInPrison(false);
                    players[i].generalMessage();
                    continue;
                }
            }
            playerTurn(players[i]);
            if (players[i].getDiceRolls().getDie1() == players[i].getDiceRolls().getDie2()) /// daca a dat dubla, mai face o tura
            {
                players[i].diceRoll();
                playerTurn(players[i]);
            }
            if (players[i].getDiceRolls().getDie1() ==
                players[i].getDiceRolls().getDie2()) /// daca a dat inca o dubla, mai face inca o tura
            {
                players[i].diceRoll();
                playerTurn(players[i]);
            }
            if (players[i].getDiceRolls().getDie1() ==
                players[i].getDiceRolls().getDie2()) /// daca a dat a treia dubla, trebuie trimis la inchisoare
            {
                std::cout << "Prea mult noroc. Mergi la inchisoare!\n";
                players[i].sendToPrison();
            }
            std::cout << "\n";
        }
    }


    std::pair<int, int> winner() /// functie ce returneaza un castigator (si numarul lor daca sunt mai multi)
    {
        int ans = 0;
        int numberOfWinners = 0;
        for (int i = 1; i <= numberOfPlayers; i++) {
            if (players[i].getEliminated() == 1)
                continue;
            if (players[ans].getBalance() < players[i].getBalance()) {
                ans = i;
                numberOfWinners = 1;
            } else if (players[ans].getBalance() == players[i].getBalance())
                numberOfWinners++;
        }
        return std::make_pair(ans, numberOfWinners);
    }

public:
    Game() {
        this->insertCardsData();
        this->readNumberOfPlayers();
        this->readPlayers();
    }
    void play() {
        for (int i = 1; i <= 25; i++) /// 25 ture
            this->turn();
        while (winner().second > 1) /// daca dupa 25 de ture sunt cel putin doi oameni cu numar maxim de bani, atunci se joaca overtime-uri de cate 5 ture
            for (int i = 1; i <= 5; i++)
                this->turn();
    }
};

#endif //OOP_GAME_H
