#ifndef INITIAL_H
#define INITIAL_H

#include <iostream>
#include <string>
#include <vector>

// Quan he ke thua
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}

    virtual double getArea() const { return width * height; }
    virtual double getPerimeter() const { return 2 * (width + height); }
    
    virtual void display() const {
        std::cout << "Hinh Chu Nhat [" << width << " x " << height << "]"
                  << " | Dien tich: " << getArea() << "\n";
    }
};

class Square : public Rectangle {
public:
    Square(double side = 0) : Rectangle(side, side) {}

    void setSide(double side) {
        width = side;
        height = side;
    }

    void display() const override {
        std::cout << "Hinh Vuong [canh: " << width << "]"
                  << " | Dien tich: " << getArea() << "\n";
    }
};

// Quan he chua dung
class Book {
private:
    std::string title;
    std::string author;

public:
    Book(std::string t = "", std::string a = "") : title(t), author(a) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }

    void display() const {
        std::cout << " - Sach: " << title << " | Tac gia: " << author << "\n";
    }
};

class Library {
private:
    std::string name;
    std::vector<Book> books;

public:
    Library(std::string n = "") : name(n) {}

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayInfo() const {
        std::cout << "Thu vien: " << name << " (Tong so: " << books.size() << " cuon)\n";
        for (const auto& b : books) {
            b.display();
        }
    }
};

#endif