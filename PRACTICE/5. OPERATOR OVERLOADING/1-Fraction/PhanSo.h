#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
    private:
        int* tuso;
        int* mauso;
    
    public:
        PhanSo();
        
        // Assignment
        PhanSo& operator=(const PhanSo& ps);

        // Operations
        PhanSo operator+(const PhanSo& ps);
        PhanSo operator-(const PhanSo& ps);
        PhanSo operator*(const PhanSo& ps);
        PhanSo operator/(const PhanSo& ps);

        PhanSo& operator+=(const PhanSo& ps);
        PhanSo& operator-=(const PhanSo& ps);
        PhanSo& operator*=(const PhanSo& ps);
        PhanSo& operator/=(const PhanSo& ps);

        PhanSo& operator++(); // Add first then assign
        PhanSo operator++(int); // Assign first then add

        PhanSo& operator--(); // Subtract first then assign
        PhanSo operator--(int); // Assign first then subtract

        // Comparison
        bool operator==(const PhanSo& ps);
        bool operator<(const PhanSo& ps);
        bool operator>(const PhanSo& ps);
        bool operator<=(const PhanSo& ps);
        bool operator>=(const PhanSo& ps);
        bool operator!=(const PhanSo& ps);

        // Iostream
        friend std::istream& operator>> (std::istream& is, PhanSo& ps);
        friend std::ostream& operator<< (std::ostream& os, const PhanSo& ps);

        // Copy && Destructor
        PhanSo(const PhanSo& other);
        ~PhanSo();
};

#endif