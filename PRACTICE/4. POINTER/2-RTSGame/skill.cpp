#include <iostream>
#include <string>
#include "rts.h"
using namespace std;

string Skill::getSkillName() const {
    return skillName;
}

unsigned int Skill::getSkillLevel() const {
    return skillLevel;
}