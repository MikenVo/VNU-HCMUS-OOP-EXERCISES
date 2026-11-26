#include <iostream>
#include "Fraction.h"
using namespace std;

// Setter
void PhanSo::GanTuSo(int tuso) {
    *(this->tuso) = tuso;
}

void PhanSo::GanMauSo(int mauso) {
    *(this->mauso) = mauso;
}

// Getter
int PhanSo::LayTuSo() const {
    return *(this->tuso);
}

int PhanSo::LayMauSo() const {
    return *(this->mauso);
}

// Operations
PhanSo PhanSo::plus(const PhanSo& f2) {
    int ketquatu, ketquamau;

    if (*(this->mauso) == *(f2.mauso)) {
        ketquatu = *(this->tuso) + *(f2.tuso);
        ketquamau = *(this->mauso);
    }
    else {
        ketquatu = (*(this->tuso) * *(f2.mauso)) + (*(f2.tuso) * *(this->mauso));
        ketquamau = *(this->mauso) * *(f2.mauso);
    }

    int gcd = PhanSo::GCD(ketquatu, ketquamau);

    return PhanSo(ketquatu / gcd, ketquamau /gcd);
}

PhanSo PhanSo::minus(const PhanSo& f2) {
    int ketquatu, ketquamau;

    if (*(this->mauso) == *(f2.mauso)) {
        ketquatu = *(this->tuso) - *(f2.tuso);
        ketquamau = *(this->mauso);
    }
    else {
        ketquatu = (*(this->tuso) * *(f2.mauso)) - (*(f2.tuso) * *(this->mauso));
        ketquamau = *(this->mauso) * *(f2.mauso);
    }

    int gcd = PhanSo::GCD(ketquatu, ketquamau);

    return PhanSo(ketquatu / gcd, ketquamau / gcd);
}

PhanSo PhanSo::multiply(const PhanSo& f2) {
    int ketquatu, ketquamau;

    ketquatu = *(this->tuso) * *(f2.tuso);
    ketquamau = *(this->mauso) * *(f2.mauso);

    int gcd = PhanSo::GCD(ketquatu, ketquamau);

    return PhanSo(ketquatu / gcd, ketquamau / gcd);
}

PhanSo PhanSo::divide(const PhanSo& f2) {
    int ketquatu, ketquamau;

    if (*(f2.tuso) == 0) {
        cout << "Divide by 0 error" << endl;
        return PhanSo();
    }
    ketquatu = *(this->tuso) * *(f2.mauso);
    ketquamau = *(this->mauso) * *(f2.tuso);

    int gcd = PhanSo::GCD(ketquatu, ketquamau);

    return PhanSo(ketquatu / gcd, ketquamau / gcd);
}

// Auxiliary Functions

void PhanSo::Input() {
    int tu, mau;
    cout << "Input numerator: ";
    cin >> tu;
    *(this->tuso) = tu;

    do
    {
        cout << "Input denominator (no 0): ";
        cin >> mau;
        if (mau == 0) {
            cout << "Invalid denominator. Input again\n";
        }
    } while (mau == 0);
    *(this->mauso) = mau;
}

// Fraction Output
void PhanSo::Output(const PhanSo &answer) const {
    int tu = answer.LayTuSo();
    int mau = answer.LayMauSo();
    int gcd = PhanSo::GCD(tu, mau);

    cout << "Fraction: " << tu / gcd << " / " << mau / gcd << endl;
}

// Number Output
double PhanSo::NumOutput(const PhanSo &answer) const {
    int tu = answer.LayTuSo();
    int mau = answer.LayMauSo();
    return (double)tu / mau;
}

int PhanSo::GCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a == 0 ? 1 : a;
}