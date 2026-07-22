#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

int main() {
    int n; cout << "Input the number of students: "; cin >> n; // Input the number of students
    cin.ignore();
    vector<Student> classroom(n);

    for (int i = 0; i < n; i++) {
        classroom[i].input();
        while (!classroom[i].validName(classroom[i].name) ||
               !classroom[i].validNumber(classroom[i].pnum) ||
               !classroom[i].validScore(classroom[i].score)) {
            cout << "Please input again!" << endl;
            classroom[i].input();
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << "----------------------" << endl;

        classroom[i].output();

        cout << "----------------------" << endl;
    }
    
    return 0;
}