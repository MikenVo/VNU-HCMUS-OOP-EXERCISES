#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <limits>
#include "student.h"

using namespace std;

void Student::input() {
    cout << "Enter the student's name: "; getline(cin, name);
    cout << "Enter the phone number: "; cin >> pnum;
    cout << "Enter the score: "; cin >> score;

    cin.ignore();
}

void Student::output() {
    cout << "Student's name: " << name << endl;
    cout << "Phone number: " << pnum << endl;
    cout << "Score: " << score << endl;
}

bool Student::validName(string name) {
    if (name.empty() || name.size() > 20) {
        return false;
    }

    for (int i = 0; i < name.size(); i++) {
        // Hợp lệ nếu là chữ cái HOẶC là khoảng trắng
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

bool Student::validNumber(string pnum) {
    if (pnum.size() >= 9 && pnum.size() <= 11) { // Check the length
        for (int i = 0; i < pnum.size(); i++) { // Check each digit
            if (!isdigit(pnum[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Student::validScore(float score) {
    if (score >= 0 && score <= 10) { // Check if the score is in the range
        return true;
    }
    return false;
}