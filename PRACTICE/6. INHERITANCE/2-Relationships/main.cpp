#include <iostream>
#include <string>
#include "initial.h"
using namespace std;

int main() {
    Rectangle rect(5.0, 3.0);
    cout << "Hinh chu nhat:" << endl;
    rect.display();
    cout << "Chu vi: " << rect.getPerimeter() << endl;

    cout << endl;

    // Khoi tao hinh vuong
    Square sq(4.0);
    cout << "Hinh vuong:" << endl;
    sq.display();
    cout << "Chu vi: " << sq.getPerimeter() << endl;

    cout << '\n' << string(40, '=') << endl;

    // Khoi tao thu vien
    Library lib("Thu Vien Trung Tam");

    // Them cac cuon sach
    Book b1("Lap Trinh C++", "Nguyen Van A");
    Book b2("Cau Truc Du Lieu", "Tran Thi B");
    Book b3("Thiet Ke Huong Doi Tuong", "Le Van C");

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    // Hien thi thong tin thu vien
    lib.displayInfo();

    return 0;
}