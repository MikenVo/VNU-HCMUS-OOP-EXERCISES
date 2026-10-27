#include <iostream>
#include "array.h"
using namespace std;

Array::Array() {
    dulieu = nullptr;
    kichthuoc = 0;
}

Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }

    delete[] dulieu;

    this->kichthuoc = other.kichthuoc;
    dulieu = new int[kichthuoc];
    for (int i = 0; i < kichthuoc; i++) {
        this->dulieu[i] = other.dulieu[i];
    }

    return *this;
}

Array::Array(const Array& other) {
    this->kichthuoc = other.kichthuoc;

    this->dulieu = new int[kichthuoc];

    for (int i = 0; i < kichthuoc; i++) {
        this->dulieu[i] = other.dulieu[i];
    }
}


Array Array::operator+(const Array& other) {
    Array result;
    if (this->kichthuoc > other.kichthuoc) {
        result.kichthuoc = this->kichthuoc;
    }
    else {
        result.kichthuoc = other.kichthuoc;
    }

    int n = result.kichthuoc;
    result.dulieu = new int[n];

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < this->kichthuoc && j < other.kichthuoc) {
        result.dulieu[k++] = this->dulieu[i++] + other.dulieu[j++];
    }

    while (i < this->kichthuoc) {
        result.dulieu[k++] = this->dulieu[i++];
    }

    while (j < other.kichthuoc) {
        result.dulieu[k++] = other.dulieu[j++];
    }

    return result;
}

Array Array::operator++(int) {
    Array result(*this);

    for (int i = 0; i < kichthuoc; i++) {
        ++this->dulieu[i];
    }

    return result;
}

Array& Array::operator++() {
    for (int i = 0; i < kichthuoc; i++) {
        ++this->dulieu[i];
    }

    return *this;
}

std::istream& operator>>(std::istream& is, Array& other) {
    cout << "Input the number of elements: ";

    delete[] other.dulieu;

    is >> other.kichthuoc;

    if (other.kichthuoc > 0) {
        other.dulieu = new int[other.kichthuoc];
        for (int i = 0; i < other.kichthuoc; i++) {
            cout << "Input element " << i + 1 << ": ";
            is >> other.dulieu[i];
        }
    }
    else {
        other.dulieu = nullptr;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Array& other) {
    os << "The size of the array: " << other.kichthuoc << "\n";
    os << "The array: [";
    for (int i = 0; i < other.kichthuoc; i++) {
        os << other.dulieu[i];
        if (i < other.kichthuoc - 1) {
            os << ", ";
        }
    }
    os << "]";

    return os;
}

Array::~Array() {
    delete[] dulieu;
    dulieu = nullptr;
    kichthuoc = 0;
}