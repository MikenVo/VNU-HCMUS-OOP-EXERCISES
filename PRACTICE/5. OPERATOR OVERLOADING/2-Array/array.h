#include <iostream>
using namespace std;

class Array {
    private:
        int* dulieu;
        int kichthuoc;

    public:
        Array();

        Array& operator=(const Array& other);
        Array(const Array& other);

        Array operator+(const Array& other);
        Array operator++(int); // Postfix ++
        Array& operator++(); // Prefix ++

        friend std::istream& operator>>(std::istream& is, Array& other);
        friend std::ostream& operator<<(std::ostream& os, const Array& other);

        ~Array();
};