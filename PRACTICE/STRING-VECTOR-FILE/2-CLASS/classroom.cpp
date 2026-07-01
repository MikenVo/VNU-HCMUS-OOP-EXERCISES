#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "classroom.h"

using namespace std;

int Classroom::checkstudent(const string& name) {
    for (int i = 0; i < studentlist.size(); i++) {
        if (studentlist[i].name == name) {
            return i;
        }
    }
    return -1;
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

void Classroom::sortClassroom() {
    sort(studentlist.begin(), studentlist.end(), [](const Student &a, const Student &b)
        { return a.score > b.score; });
}

void Classroom::addstudent() {
    Student newstudent;
    cout << "Nhap ten hoc sinh: ";
    getline(cin >> ws, newstudent.name);

    if (checkstudent(newstudent.name) != -1) {
        cout << "Da co hoc sinh trong lop" << endl;
        return;
    }

    if (!newstudent.validName(newstudent.name)) {
        cout << "Khong hop le (Ten qua dai hoac trong)!" << endl;
        return;
    }

    cout << "Nhap so dien thoai: ";
    cin >> newstudent.pnum;
    if (!newstudent.validNumber(newstudent.pnum)) {
        cout << "Khong hop le (SDT phai tu 9-11 so)!" << endl;
        return;
    }

    cout << "Nhap diem so: ";
    cin >> newstudent.score;
    if (!newstudent.validScore(newstudent.score)) {
        cout << "Khong hop le (Diem phai tu 0-10)!" << endl;
        return;
    }

    studentlist.push_back(newstudent);
    cout << "Da them hoc sinh thanh cong" << endl;
    sortClassroom();
}

void Classroom::delstudent() {
    Student student;
    cout << "Nhap ten hoc sinh: "; getline(cin >> ws, student.name);
    int index = checkstudent(student.name);
    if (index != -1) {
        studentlist.erase(studentlist.begin() + index);
        cout << "Da xoa hoc sinh thanh cong" << endl;
        return;
    }
    cout << "Khong co hoc sinh trong lop" << endl;
}

void Classroom::input() {
    fstream list;
    list.open("LopHoc.txt", fstream::in);
    if (list.fail()) {
        cout << "Khong the mo tep tin" << endl;
        return;
    }

    int n; list >> n; // Get the number of students
    for (int i = 0; i < n; i++) {
        Student student;
        list >> ws;
        getline(list, student.name);
        list >> student.pnum;
        list >> student.score;

        studentlist.push_back(student);
    }
    list.close();

    sortClassroom();
}

void Classroom::output() {
    cout << "-------Student list-------" << endl;
    for (int i = 0; i < studentlist.size(); i++) {
        cout << "Ho va ten: " << studentlist[i].name << endl;
        cout << "So dien thoai: " << studentlist[i].pnum << endl;
        cout << "Diem: " << studentlist[i].score << endl;
        cout << endl;
    }
}