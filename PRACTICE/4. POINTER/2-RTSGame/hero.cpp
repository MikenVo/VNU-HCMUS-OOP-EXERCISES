#include <iostream>
#include <string>
#include <vector>
#include "rts.h"
using namespace std;

// Setter
void Hero::setName(string name) {
    heroName = name;
}

void Hero::setHealth(unsigned int health) {
    heroHealth = health;
}

void Hero::setMana(unsigned int mana) {
    heroMana = mana;
}

void Hero::setLevel(unsigned int level) {
    heroLevel = level;
}

void Hero::setSkill(unsigned int numskill) {
    for (Skill *s : skillList) { // Clear te out skill list if an object is create before
        delete s;
    }
    skillList.clear();

    for (int i = 0; i < numskill; i++) {
        string skillname;
        cout << "Input skill " << i + 1 << ": ";
        getline(cin, skillname);

        unsigned int skilllevel;
        cout << "Input the level of that skill: ";
        cin >> skilllevel;
        cin.ignore();

        skillList.push_back(new Skill(skillname, skilllevel));
    }
}

// Getter
string Hero::getName() const {
    return heroName;
}

unsigned int Hero::getHealth() const {
    return heroHealth;
}

unsigned int Hero::getMana() const {
    return heroMana;
}

unsigned int Hero::getLevel() const {
    return heroLevel;
}

vector <Skill> Hero::getSkill() const {
    vector <Skill> learnedskills;
    int herolevel = getLevel();

    for (Skill* s : skillList) {
        if (herolevel >= s->getSkillLevel()) {
            learnedskills.push_back(*s);
        }
    }

    return learnedskills;
}

void Hero::CutSkill(unsigned int numcut) {
    if (numcut > skillList.size()) {
        for (Skill* s : skillList) {
            delete s;
        }
        skillList.clear();
        return;
    }

    for (unsigned int i = 0; i < numcut; i++) {
        Skill* lastskill = skillList.back();
        delete lastskill;

        skillList.pop_back();
    }
}

// Auxiliary functions
void Hero::Input() {
    int choice;
    cout << "Game options" << endl;
    cout << "1. Use the default character" << endl;
    cout << "2. Create a new character" << endl;
    cout << "Input your option: "; cin >> choice; cin.ignore();

    if (choice == 1) {
        setName("Yasuo");
        setHealth(590);
        setMana(0);
        setLevel(1);

        for (Skill *s : skillList) delete s;
        skillList.clear();
        skillList.push_back(new Skill("Steel Tempest", 1));
        skillList.push_back(new Skill("Wind Wall", 2));
        skillList.push_back(new Skill("Sweeping Blade", 3));
        skillList.push_back(new Skill("Last Breath", 10));

        cout << "Default hero has been created.\nWelcome Yasuo!\n";
    }
    else if (choice == 2) {
        string name;
        cout << "Type the hero's name: ";
        getline(cin >> ws, name);

        unsigned int health;
        cout << "Type the hero's health: ";
        cin >> health;

        unsigned int mana;
        cout << "Type the hero's mana: ";
        cin >> mana;

        unsigned int level;
        cout << "Type the hero's level: ";
        cin >> level;

        unsigned int numskills;
        cout << "Type the number of skills: ";
        cin >> numskills;
        cin.ignore();

        *this = Hero(name, health, mana, level, numskills);

        cout << "New hero has been created.\n";
        cout << "Welcome " << getName() << "!\n";
    }
}

void Hero::Output() {
    cout << "Hero information" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Mana: " << getMana() << endl;
    cout << "Skills: " << endl;

    vector<Skill> skills = getSkill();
    int index = 1;
    for (const Skill &s : skills) {
        cout << index++ << ". " << s.getSkillName() << endl;
    }
}