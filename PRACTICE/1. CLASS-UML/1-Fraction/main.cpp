#include <iostream>
#include "initialization.h"

using namespace std;

int main() {
    // Initialization
    Fraction frac1;
    Fraction frac2;
    Fraction result;
    double result2 = 0;

    // Input
    frac1.inputfrac();
    frac2.inputfrac();

    // Fraction output
    cout << "Fraction 1: "; frac1.outputfrac();
    cout << "Fraction 2: "; frac2.outputfrac();

    // Addition
    result = frac1.add(frac2);
    cout << "Addition result: "; result.outputfrac();
    
    // Subtraction
    result = frac1.minus(frac2);
    cout << "Subtraction result: "; result.outputfrac();

    // Multiplication
    result = frac1.multiply(frac2);
    cout << "Multiplication result: "; result.outputfrac();

    // Division
    frac1.divide(frac2);

    return 0;
}