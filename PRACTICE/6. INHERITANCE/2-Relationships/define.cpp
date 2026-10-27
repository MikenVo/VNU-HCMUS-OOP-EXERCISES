#include <iostream>
#include <vector>
#include <string>
#include "initial.h"
using namespace std;

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}

void Rectangle::display() const {
    cout << "Hinh Chu Nhat [" << width << " x " << height << "]" << " | Dien tich: " << getArea() << "\n";
}

Square::Square(double side) : Rectangle(side, side) {}

void Square::setSide(double side) {
    width = side;
    height = side;
}

void Square::display() const {
    cout << "Hinh Vuong [canh: " << width << "]" << " | Dien tich: " << getArea() << "\n";
}

Book::Book(string t, string a) {
    title = t;
    author = a;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

void Book::display() const {
    cout << " - Sach: " << title << " | Tac gia: " << author << "\n";
}

Library::Library(string n) {
    name = n;
}

void Library::addBook(const Book &book) {
    books.push_back(book);
}

void Library::displayInfo() const {
    cout << "Thu vien: " << name << " (Tong so: " << books.size() << " cuon)\n";
    for (int i = 0; i < books.size(); i++) {
        books[i].display();
    }
}