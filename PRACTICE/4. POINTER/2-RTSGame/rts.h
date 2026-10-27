#ifndef RTS_H
#define RTS_H

#include <iostream>
#include <string>
#include <vector>

class Skill {
    std::string skillName;
    unsigned int skillLevel;

    public:
        Skill(std::string name, unsigned int level) {
            skillName = name;
            skillLevel = level;
        }

        std::string getSkillName() const;
        unsigned int getSkillLevel() const;
};

class Hero {
    std::string heroName; // The name of the hero
    unsigned int heroHealth; // The health of the hero
    unsigned int heroMana; // The mana of the hero
    unsigned int heroLevel; // The level of the hero
    std::vector<Skill*> skillList; // The list of the skill

    public:
        // Setter
        void setName(std::string name);
        void setHealth(unsigned int health);
        void setMana(unsigned int mana);
        void setLevel(unsigned int level);
        void setSkill(unsigned int numskills);

        // Getter
        std::string getName() const;
        unsigned int getHealth() const;
        unsigned int getMana() const;
        unsigned int getLevel() const;
        std::vector<Skill> getSkill() const; // This function will only display the skills that the player can learn

        void CutSkill(unsigned int numcut); // This function will take the skills from the list no matter it is a learned or unlearned skil

        // Constructors
        Hero() {
            heroName = "Yasuo";
            heroHealth = 590;
            heroMana = 0;
            heroLevel = 1;

            skillList.push_back(new Skill("Steel Tempest", 1));
            skillList.push_back(new Skill("Wind Wall", 2));
            skillList.push_back(new Skill("Sweeping Blade", 3));
            skillList.push_back(new Skill("Last Breath", 10));
        }

        Hero(std::string name, unsigned int health, unsigned int mana, unsigned int level, unsigned int numskills) {
            skillList.clear();
            setName(name);
            setHealth(health);
            setMana(mana);
            setLevel(level);
            setSkill(numskills);
        }

        Hero(const Hero& other) {
            heroName = other.getName();
            heroHealth = other.getHealth();
            heroMana = other.getMana();
            heroLevel = other.getLevel();
            for (Skill *s : other.skillList) {
                skillList.push_back(new Skill(s->getSkillName(), s->getSkillLevel()));
            }
        }

        Hero &operator=(const Hero &other) {
            if (this != &other) {
                for (Skill *s : skillList)
                    delete s;
                skillList.clear();

                heroName = other.heroName;
                heroHealth = other.heroHealth;
                heroMana = other.heroMana;
                heroLevel = other.heroLevel;
                for (Skill *s : other.skillList) {
                    skillList.push_back(new Skill(s->getSkillName(), s->getSkillLevel()));
                }
            }
            return *this;
        }

        ~Hero() {
            for (Skill* s : skillList) {
                delete s;
            }
        }

        // Auxiliary Functions
        void Input();
        void Output();
};

#endif