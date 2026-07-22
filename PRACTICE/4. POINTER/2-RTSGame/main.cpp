#include <iostream>
#include <string>
#include <vector>
#include "rts.h"
using namespace std;

int main() {
    Hero hero;
    hero.Input();

    char ans;
    cout << "Do you want to take out some skills? (Y/N): ";
    cin >> ans;

    if (ans == 'Y' || ans == 'y')
    {
        unsigned int numcut;
        cout << "Input the number of skills: ";
        cin >> numcut;
        hero.CutSkill(numcut);
        cout << "The system has taken out " << numcut << " skills.\n";
    }

    hero.Output();
    return 0;
}