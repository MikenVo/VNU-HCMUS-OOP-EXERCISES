#include <iostream>
#include <string>
#include "initial.h"
using namespace std;

int main() {
    Complex cnum;
    Complex cnum2;
    cin >> cnum;
    cout << endl;
    cin >> cnum2;

    cout << "\n-----Complex number 1-----" << endl;
    cout << cnum << endl;

    cout << "\n-----Complex number 2-----" << endl;
    cout << cnum2 << endl;

    cout << "\n-----Operations-----" << endl;
    cout << (cnum + cnum2) << endl;
    cout << (cnum - cnum2) << endl;
    cout << (cnum * cnum2) << endl;

    return 0;
}