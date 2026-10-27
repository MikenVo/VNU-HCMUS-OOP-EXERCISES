#include <iostream>
#include "PhanSo.h"
using namespace std;

int main() {
    PhanSo a;
    cin >> a;

    PhanSo b;
    cin >> b;

    cout << "+: " << (a + b) << endl;
    cout << "-: " << (a - b) << endl;
    cout << "*: " << (a * b) << endl;
    cout << "/: " << (a / b) << endl;

    PhanSo c = a;

    cout << "+=: " << (c += b) << endl; c = a;
    cout << "-=: " << (c -= b) << endl; c = a;
    cout << "*=: " << (c *= b) << endl; c = a;
    cout << "/=: " << (c /= b) << endl; c = a;

    cout << "++ (prefix): " << ++c << endl;
    cout << "++ (postfix): " << c++ << endl;

    cout << "-- (postfix): " << c-- << endl;
    cout << "-- (prefix): " << --c << endl;

    cout << std::boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a != b: " << (a != b) << endl;

    return 0;
}