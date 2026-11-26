#ifndef STUDENT
#define STUDENT

#include <string>
using namespace std;

class Student {
    public:
        string name; // 20 characters including the spaces
        string pnum; // 9 to 11 characters, only numbers
        float score; // 0 to 10

        void input();
        void output();
        bool validName(string name); // Check the validation of the name length
        bool validNumber(string pnum); // Check the validation of the phone number length and characters
        bool validScore(float score); // Check the validation of the score
};

#endif