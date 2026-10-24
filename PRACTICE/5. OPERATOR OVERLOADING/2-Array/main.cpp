#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array a; cin >> a;
    Array b; cin >> b;

    // +
    cout << (b + a) << endl;

    // ++
    cout << a++ << endl;
    cout << ++a << endl;

    return 0;
}