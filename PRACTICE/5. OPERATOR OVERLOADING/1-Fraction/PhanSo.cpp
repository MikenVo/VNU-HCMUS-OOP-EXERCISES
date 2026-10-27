#include <iostream>
#include "PhanSo.h"
using namespace std;

PhanSo::PhanSo() {
    tuso = new int(0);
    mauso = new int(0);
}

// ---------------------------------------------------------------------------------

// Assignment
PhanSo& PhanSo::operator=(const PhanSo& other) {
    if (this == &other) {
        return *this;
    }

    delete tuso;
    delete mauso;

    tuso = new int;
    mauso = new int;

    *this->tuso = *other.tuso;
    *this->mauso = *other.mauso;
    
    return *this;
}

// ---------------------------------------------------------------------------------

// Operations
PhanSo PhanSo::operator+(const PhanSo& other) {
    PhanSo result;
    *result.tuso = (*this->tuso) * (*other.mauso) + (*this->mauso) * (*other.tuso);
    *result.mauso = (*this->mauso) * (*other.mauso);
    return result;
}

PhanSo PhanSo::operator-(const PhanSo& other) {
    PhanSo result;
    *result.tuso = (*this->tuso) * (*other.mauso) - (*this->mauso) * (*other.tuso);
    *result.mauso = (*this->mauso) * (*other.mauso);
    return result;
}

PhanSo PhanSo::operator*(const PhanSo& other) {
    PhanSo result;
    *result.tuso = (*this->tuso) * (*other.tuso);
    *result.mauso = (*this->mauso) * (*other.mauso);
    return result;
}

PhanSo PhanSo::operator/(const PhanSo& other) {
    PhanSo result;
    if (*other.tuso == 0) {
        return result;
    }

    *result.tuso = (*this->tuso) * (*other.mauso);
    *result.mauso = (*this->mauso) * (*other.tuso);
    return result;
}

PhanSo& PhanSo::operator+=(const PhanSo& other) {
    int tuso = *this->tuso * *other.mauso + *this->mauso * *other.tuso;
    int mauso = *this->mauso * *other.mauso;

    *this->tuso = tuso;
    *this->mauso = mauso;
    return *this;
}

PhanSo& PhanSo::operator-=(const PhanSo& other) {
    int tuso = (*this->tuso) * (*other.mauso) - (*this->mauso) * (*other.tuso);
    int mauso = *this->mauso * *other.mauso;

    *this->tuso = tuso;
    *this->mauso = mauso;
    return *this;
}

PhanSo& PhanSo::operator*=(const PhanSo& other) {
    int tuso = (*this->tuso) * (*other.tuso);
    int mauso = (*this->mauso) * (*other.mauso);

    *this->tuso = tuso;
    *this->mauso = mauso;
    return *this;
}

PhanSo& PhanSo::operator/=(const PhanSo& other) {
    if (*this->tuso == 0 || *other.tuso == 0) {
        *this->tuso = 0;
        *this->mauso = 1;
        return *this;
    }

    int tuso = (*this->tuso) * (*other.mauso);
    int mauso = (*this->mauso) * (*other.tuso);

    *this->tuso = tuso;
    *this->mauso = mauso;
    return *this;
}

PhanSo& PhanSo::operator++() {
    int tuso = 1 * *this->mauso + *this->tuso;
    *this->tuso = tuso;
    return *this;
}

PhanSo PhanSo::operator++(int) {
    PhanSo result(*this);
    int tuso = 1 * *this->mauso + *this->tuso;
    *this->tuso = tuso;
    return result;
}

PhanSo& PhanSo::operator--() {
    int tuso = *this->tuso - 1 * *this->mauso;
    *this->tuso = tuso;
    return *this;
}

PhanSo PhanSo::operator--(int) {
    PhanSo result(*this);
    int tuso = *this->tuso - 1 * *this->mauso;
    *this->tuso = tuso;
    return result;
}

// ---------------------------------------------------------------------------------

// Comparison
bool PhanSo::operator==(const PhanSo& other) {
    int result = *this->tuso * *other.mauso - *this->mauso * *other.tuso;

    if (result == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool PhanSo::operator<(const PhanSo& other) {
    int tuso1 = *this->tuso * *other.mauso;
    int tuso2 = *other.tuso * *this->mauso;

    if (tuso1 < tuso2) {
        return true;
    }
    else {
        return false;
    }
}

bool PhanSo::operator>(const PhanSo& other) {
    int tuso1 = *this->tuso * *other.mauso;
    int tuso2 = *other.tuso * *this->mauso;

    if (tuso1 > tuso2) {
        return true;
    }
    else {
        return false;
    }
}

bool PhanSo::operator<=(const PhanSo& other) {
    int tuso1 = *this->tuso * *other.mauso;
    int tuso2 = *other.tuso * *this->mauso;

    if (tuso1 < tuso2 || tuso1 == tuso2) {
        return true;
    }
    else {
        return false;
    }
}

bool PhanSo::operator>=(const PhanSo& other) {
    int tuso1 = *this->tuso * *other.mauso;
    int tuso2 = *other.tuso * *this->mauso;

    if (tuso1 > tuso2 || tuso1 == tuso2) {
        return true;
    }
    else {
        return false;
    }
}

bool PhanSo::operator!=(const PhanSo& other) {
    int result = *this->tuso * *other.mauso - *this->mauso * *other.tuso;

    if (result != 0) {
        return true;
    }
    else {
        return false;
    }
}

// ---------------------------------------------------------------------------------

// Copy
PhanSo::PhanSo(const PhanSo& other) {
    tuso = new int(*other.tuso);
    mauso = new int(*other.mauso);
}

// Destructor
PhanSo::~PhanSo() {
    delete tuso;
    delete mauso;
}

// Iostream

std::istream& operator>> (std::istream& is, PhanSo &ps) {
    cout << "Nhap tu so: ";
    is >> *ps.tuso;
    
    cout << "Nhap mau so: ";
    is >> *ps.mauso;
    return is;
}

std::ostream &operator<<(std::ostream &os, const PhanSo &ps) {
    // Kiểm tra an toàn bộ nhớ trước khi giải tham chiếu
    if (ps.tuso == nullptr || ps.mauso == nullptr)
    {
        os << "0/1";
        return os;
    }

    // Bắt buộc phải dùng dấu * để lấy giá trị số nguyên ra in
    os << *ps.tuso << "/" << *ps.mauso;
    return os;
}