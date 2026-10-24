#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "game.h"

Commander::Commander(std::string name, int credits) {
    this->name = name;
    this->credits = credits;
    this->fleetCraft.clear();
    this->structures.clear();
}

std::ostream& operator<<(std::ostream& os, const Commander &cmd) {
    os << "===== Commander " << cmd.name << " =====" << std::endl;
    os << "1. Name: " << cmd.name << std::endl;
    os << "2. Current credits: " << cmd.credits << std::endl;
    os << "3. Fleet information: " << std::endl;
    int fleetCraftNum = cmd.fleetCraft.size();
    for (int i = 0; i < fleetCraftNum; i++) {
        os << "    3." << i + 1 << ". " << cmd.fleetCraft[i]->getID() << std::endl;
    }
    os << "4. Structures information: " << std::endl;
    int structNum = cmd.structures.size();
    for (int i = 0; i < structNum; i++) {
        os << "    4." << i + 1 << ". " << cmd.structures[i]->getID() << std::endl;
    }
    return os;
}

std::string Commander::getName() {
    return this->name;
}

void Commander::addStructure(SpaceStructure* structure) {
    if (structure != nullptr) {
        structures.push_back(structure);
    }
}

void Commander::addCraft(Spacecraft* craft) {
    if (craft != nullptr) {
        fleetCraft.push_back(craft);
        craft->setOwner(this);
    }
}

std::vector<SpaceStructure*> Commander::getStructures() {
    return structures;
}

std::vector<Spacecraft*> Commander::getCrafts() {
    return fleetCraft;
}

void Commander::moveTo(int id, float x, float y) {
    // Tim dung con tau roi moi keu no di chuyen
    int fleetCraftNum = fleetCraft.size();
    for (int i = 0; i < fleetCraftNum; i++) {
        if (fleetCraft[i]->getID() == id) {
            std::cout << "Moving the spacecraft" << std::endl;
            SpaceEntity::Position newpos = {x, y};
            fleetCraft[i]->moveTo(newpos);
            return;
        }
    }
    std::cout << "The spacecraft is not found" << std::endl;
}

void Commander::fleetmoveTo(float x, float y) {
    int fleetCraftNum = fleetCraft.size();
    std::cout << "Moving the fleet" << std::endl;
    SpaceEntity::Position newpos = {x, y};
    for (int i = 0; i < fleetCraftNum; i++) {
        fleetCraft[i]->moveTo(newpos);
    }
}

void Commander::structureCommand() {
    std::cout << "----- Structure commands -----" << std::endl;
    for (int i = 0; i < structures.size(); i++) {
        if (dynamic_cast<Shipyard*>(structures[i]) != nullptr) {
            std::cout << i + 1 << ". Shipyard " << structures[i]->getID() << std::endl;
        }
    }
    int choice;
    std::cout << "Choose a structure to operate (Enter ID): ";
    std::cin >> choice;
    std::cin.ignore(1000, '\n');

    std::cout << "\n1. Scout ship" << std::endl;
    std::cout << "\n2. Fighter ship" << std::endl;
    std::cout << "Choose a prototype to build (Enter name): ";
    std::string choice2;
    getline(std::cin, choice2);

    Shipyard *selectedYard = nullptr;
    for (size_t i = 0; i < structures.size(); i++) {
        if (structures[i]->getID() == choice) {
            selectedYard = dynamic_cast<Shipyard*>(structures[i]);
            break;
        }
    }

    if (selectedYard != nullptr) {
        if (choice2 == "Scout ship" || choice2 == "scout ship" || choice2 == "1") {
            static ScoutShip scoutProto;
            selectedYard->setPrototype(&scoutProto);

            Spacecraft *newCraft = selectedYard->produceCraft();
            if (newCraft != nullptr) {
                this->addCraft(newCraft);
            }
            selectedYard->unownedSpaceCraft.pop_back(); // Loai bo di tau o danh sach chua so huu
        }
        else if (choice2 == "Fighter ship" || choice2 == "fighter ship" || choice2 == "2") {
            static FighterShip fighterProto;
            selectedYard->setPrototype(&fighterProto);

            Spacecraft *newCraft = selectedYard->produceCraft();
            if (newCraft != nullptr) {
                this->addCraft(newCraft);
            }
            selectedYard->unownedSpaceCraft.pop_back();
        }
    }
    else {
        std::cout << "Invalid Ship yard ID" << std::endl;
    }
}

Commander::~Commander() {
    for (int i = 0; i < fleetCraft.size(); i++) {
        delete fleetCraft[i];
    }
    fleetCraft.clear();

    for (int i = 0; i < structures.size(); i++) {
        delete structures[i];
    }
    structures.clear();
}