#include <iostream>
#include <vector>
#include <string>
#include "game.h"

class TechModule;

void Spacecraft::moveTo(Position newPos) {
    position = newPos;
    state = "Moving";
    std::cout << "Spacecraft " << id << " is moving to (" << position.x << ", " << position.y << ")" << std::endl;
}

void Spacecraft::setOwner(Commander* cmd) {
    this->owner = cmd;
}

int Spacecraft::getHull() const {
    return hull;
}

int Spacecraft::getSpeed() const {
    return speed;
}

void Spacecraft::SetHull(int newHull) {
    hull = newHull;
}

void Spacecraft::SetSpeed(int newSpeed) {
    speed = newSpeed;
}

std::vector<TechModule*> Spacecraft::getTechList() {
    return tech;
}

void Spacecraft::addTech(TechModule* newTech) {
    if (newTech != nullptr) tech.push_back(newTech);
}

// ===== Scout ship =====
ScoutShip::ScoutShip() {
    this->hull = 500;
    this->speed = 800;
    this->owner = nullptr;
    this->state = "Idle";
    this->totalEP = 1000;
    this->id = 0;

    this->skills.push_back({"Invisible", 100});
    this->skills.push_back({"Sabotage", 500});

    this->tech.clear(); // Ban dau tau se khong co cong nghe nao het
}

ScoutShip::ScoutShip(const ScoutShip& ss) {
    this->hull = ss.hull;
    this->speed = ss.speed;
    this->owner = ss.owner;
    this->state = "Idle";
    this->totalEP = ss.totalEP;
    this->skills = ss.skills;
    this->id = ss.id + 1;
    this->tech.reserve(ss.tech.size());
    for (int i = 0; i < ss.tech.size(); i++) {
        this->tech.push_back(ss.tech[i]);
    }
}

Spacecraft* ScoutShip::clone() const {
    return new ScoutShip(*this);
}

void ScoutShip::draw() const {
    std::cout << "===== Scout ship " << id << " =====" << std::endl;
    std::cout << "1. Hull: " << hull << std::endl;
    std::cout << "2. Speed: " << speed << std::endl;
    std::cout << "3. Current commander: " << (owner != nullptr ? owner->getName() : "None") << std::endl;
    std::cout << "4. State: " << state << std::endl;
    std::cout << "5. Total energy point: " << totalEP << std::endl;
    std::cout << "6. Skills: " << std::endl;
    for (int i = 0; i < skills.size(); i++) {
        std::cout << "    6." << i + 1 << ". " << skills[i].name << std::endl;
    }
    std::cout << "7. Techs: " << std::endl;
    for (int i = 0; i < tech.size(); i++) {
        std::cout << "    7." << i + 1 << ". " << tech[i]->getTechName() << std::endl;
    }
}

void ScoutShip::useSkill(std::string name) {
    for (int i = 0; i < skills.size(); i++) {
        if (skills[i].name == name) {
            if (totalEP < skills[i].ep) {
                std::cout << "Not enough Energy Points to use " << name << std::endl;
                return;
            }
            totalEP -= skills[i].ep;
            if (totalEP <= 0) totalEP = 0;
            std::cout << "Scout ship used weapon: " << name << ". Remaining EP: " << totalEP << std::endl;
            return;
        }
    }
    std::cout << "The weapon is not found" << std::endl;
}

void ScoutShip::update() {
    if (totalEP < 100) {
        totalEP += 50;
        if (totalEP > 100)
            totalEP = 1000;
    }

    if (state == "Moving") {
        position.x += speed * 0.1f;
        position.y += speed * 0.1f;
        state = "Idle";
    }
}

ScoutShip::~ScoutShip() {
    owner = nullptr;
    for (int i = 0; i < tech.size(); i++) {
        delete tech[i];
    }
    tech.clear();
}



// ===== Fighter ship =====
FighterShip::FighterShip() {
    this->hull = 1000;
    this->speed = 500;
    this->owner = nullptr;
    this->state = "Idle";
    this->totalEP = 2000;
    this->id = 0;

    this->skills.push_back({"Chopper shots", 300});
    this->skills.push_back({"Holy Shield", 100});
    this->skills.push_back({"Pulse Canon", 1000});
    this->skills.push_back({"Autorocket", 500});
}

FighterShip::FighterShip(const FighterShip& fs) {
    this->hull = fs.hull;
    this->speed = fs.speed;
    this->owner = fs.owner;
    this->state = "Idle";
    this->totalEP = fs.totalEP;
    this->skills = fs.skills;
    this->id = fs.id + 1;
    this->tech.reserve(fs.tech.size());
    for (int i = 0; i < fs.tech.size(); i++) {
        this->tech.push_back(fs.tech[i]);
    }
}

Spacecraft* FighterShip::clone() const {
    return new FighterShip(*this);
}

void FighterShip::update() {
    if (totalEP < 100) {
        totalEP += 100;
        if (totalEP > 100)
            totalEP = 2000;
    }

    if (state == "Moving") {
        position.x += speed * 0.1f;
        position.y += speed * 0.1f;
        state = "Idle";
    }
}

void FighterShip::draw() const {
    std::cout << "===== FighterShip ship " << id << " =====" << std::endl;
    std::cout << "1. Hull: " << hull << std::endl;
    std::cout << "2. Speed: " << speed << std::endl;
    std::cout << "3. Current commander: " << (owner != nullptr ? owner->getName() : "None") << std::endl;
    std::cout << "4. State: " << state << std::endl;
    std::cout << "5. Total energy point: " << totalEP << std::endl;
    std::cout << "6. Skills: " << std::endl;
    for (int i = 0; i < skills.size(); i++) {
        std::cout << "    6." << i + 1 << ". " << skills[i].name << std::endl;
    }
    std::cout << "7. Techs: " << std::endl;
    for (int i = 0; i < tech.size(); i++) {
        std::cout << "    7." << i + 1 << ". " << tech[i]->getTechName() << std::endl;
    }
}

void FighterShip::useSkill(std::string name) {
    for (int i = 0; i < skills.size(); i++) {
        if (skills[i].name == name) {
            if (totalEP < skills[i].ep) {
                std::cout << "Not enough Energy Points to use " << name << std::endl;
                return;
            }
            totalEP -= skills[i].ep;
            if (totalEP <= 0)
                totalEP = 0;
            std::cout << "Scout ship used weapon: " << name << ". Remaining EP: " << totalEP << std::endl;
            return; // Dừng hàm ngay khi dùng xong
        }
    }
    std::cout << "The weapon is not found" << std::endl;
}

FighterShip::~FighterShip() {
    owner = nullptr;
    for (int i = 0; i < tech.size(); i++) {
        delete tech[i];
    }
    tech.clear();
}

/*
class Fleet : public SpaceEntity { // Composite
private:
    std::vector<Spacecraft *> members;

public:
    void addCraft(Spacecraft *craft);
    void removeCraft(Spacecraft *craft);
    void update() override;
    void draw() const override;
    friend Fleet operator+(const Fleet &fleetA, const Fleet &fleetB);
};
*/

void Fleet::addCraft(Spacecraft* craft) {
    if (craft != nullptr) members.push_back(craft);
}

void Fleet::removeCraft(Spacecraft *craft) {
    if (craft == nullptr)
        return;

    for (size_t i = 0; i < members.size(); i++) {
        if (members[i] == craft) {
            members.erase(members.begin() + i);
            std::cout << "Removed craft from fleet successfully" << std::endl;
            return;
        }
    }

    std::cout << "Craft is not found in this fleet" << std::endl;
}

void Fleet::update() {
    for (int i = 0; i < members.size(); i++) {
        members[i]->update();
    }
}

void Fleet::draw() const {
    std::cout << "\n\n===== Fleet Information =====" << std::endl;
    for (int i = 0; i < members.size(); i++) {
        members[i]->draw();
    }
}

Fleet operator+(const Fleet &fleetA, const Fleet &fleetB) {
    Fleet newFleet;
    
    for (int i = 0; i < fleetA.members.size(); i++) {
        newFleet.addCraft(fleetA.members[i]);
    }

    for (int i = 0; i < fleetB.members.size(); i++) {
        newFleet.addCraft(fleetB.members[i]);
    }

    return newFleet;
}

// class Armada : public SpaceEntity {
// private:
//     std::vector<SpaceEntity *> members;

// public:
//     void update() override;
//     void draw() const override;
//     void addMember(SpaceEntity *SE);
//     ~Armada();
// };

void Armada::update() {
    for (int i = 0; i < members.size(); i++) {
        members[i]->update();
    }
}

void Armada::draw() const {
    std::cout << "\n\n===== Armanda Information =====" << std::endl;
    for (int i = 0; i < members.size(); i++) {
        members[i]->draw();
    }
}

void Armada::addMember(SpaceEntity* SE) {
    if (SE != nullptr) members.push_back(dynamic_cast<SpaceEntity*>(SE));
}

Armada::~Armada() {
    for (int i = 0; i < members.size(); i++) {
        members.erase(members.begin() + i);
    }
    members.clear();
}


