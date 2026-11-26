#include <iostream>
#include <string>
#include <iomanip>
#include "initial.h"
using namespace std;

Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

Complex& Complex::operator=(const Complex& other) {
    if (this == &other) return *this;

    this->real = other.real;
    this->imag = other.imag;
    return *this;
}

Complex::Complex(const Complex& other) {
    this->real = other.real;
    this->imag = other.imag;
}

Complex::~Complex() {}

Complex Complex::operator-(const Complex& other) {
    Complex result;
    result.real = this->real - other.real;
    result.imag = this->imag - other.imag;
    return result;
}

Complex Complex::operator+(const Complex &other) {
    Complex result;
    result.real = this->real + other.real;
    result.imag = this->imag + other.imag;
    return result;
}

Complex Complex::operator*(const Complex& other) {
    Complex result;
    result.real = (this->real) * (other.real) - (this->imag) * (other.imag);
    result.imag = (this->real) * (other.imag) + (this->imag) * (other.real);
    return result;
}

istream& operator>>(istream& is, Complex& cnum) {
    cout << "Input the real number: ";
    is >> cnum.real;
    cout << "Input the imaginary number: ";
    is >> cnum.imag;
    return is;
}

ostream& operator<< (ostream& os, const Complex& cnum) {
    os << "The complex number: " << setprecision(3) << fixed << (cnum.real) << " + " << (cnum.imag) << "i";
    return os;
}