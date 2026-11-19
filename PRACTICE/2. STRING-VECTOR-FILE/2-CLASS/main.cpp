#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "classroom.h"

using namespace std;

int main() {
    Classroom studentlist;
    studentlist.input();
    
    while (true) {
        cout << "-------Thao tac-------" << endl;
        cout << "1. Them hoc sinh" << endl;
        cout << "2. Xoa hoc sinh" << endl;
        cout << "3. In danh sach hoc sinh" << endl;
        cout << "4. Thoat chuong trinh" << endl;
        int op; cout << "Vui long nhap thao tac: "; cin >> op;

        if (op == 1) {
            studentlist.addstudent();
        }
        else if (op == 2) {
            studentlist.delstudent();
        }
        else if (op == 3) {
            studentlist.output();
        }
        else if (op == 4) {
            cout << "Thoat chuong trinh..." << endl;
            break;
        }
    }

    return 0;
}