#include <iostream>
#include <string>
using namespace std;

class Complex {
    private:
        double real;
        double imag;

    public:
        Complex();

        Complex (double r, double i);

        Complex& operator=(const Complex &other);
        ~Complex();
        Complex(const Complex& other);

        Complex operator-(const Complex& other);
        Complex operator*(const Complex& other);
        Complex operator+(const Complex& other);

        friend istream& operator>>(istream& is, Complex& cnum);
        friend ostream& operator<<(ostream& os, const Complex& cnum);
};