#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    PhanSo f1, f2, result;
    int choice = 0;

    cout << "--- Enter the first fraction ---\n";
    f1.Input();

    cout << "\n--- Enter the second fraction ---\n";
    f2.Input();

    cout << "\n========================================\n";
    cout << "CHOOSE AN OPERATION:\n";
    cout << "1. Plus (+)\n";
    cout << "2. Minus (-)\n";
    cout << "3. Multiply (*)\n";
    cout << "4. Divide (/)\n";
    cout << "========================================\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    cout << "----------------------------------------\n";

    if (choice == 1) {
        result = f1.plus(f2);
        cout << "Result of Addition:\n";
        result.Output(result);
        cout << "Decimal: " << result.NumOutput(result) << endl;
    }
    else if (choice == 2) {
        result = f1.minus(f2);
        cout << "Result of Subtraction:\n";
        result.Output(result);
        cout << "Decimal: " << result.NumOutput(result) << endl;
    }
    else if (choice == 3) {
        result = f1.multiply(f2);
        cout << "Result of Multiplication:\n";
        result.Output(result);
        cout << "Decimal: " << result.NumOutput(result) << endl;
    }
    else if (choice == 4) {
        result = f1.divide(f2);
        if (f2.LayTuSo() != 0) {
            cout << "Result of Division:\n";
            result.Output(result);
            cout << "Decimal: " << result.NumOutput(result) << endl;
        }
    }
    else {
        cout << "Invalid choice! Please restart the program and enter a number from 1 to 4.\n";
    }

    return 0;
}