#include <iostream>
using namespace std;

int main() {
    int width = 10;
    int height = 5;

    cout << string(width, '*') << endl;
    for (int i = 0; i < height - 2; i++) {
        cout << ('*') << string(width - 2, ' ') << ('*') << endl;
    }
    cout << string(width, '*') << endl;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cout << '*';
        }
        cout << endl;
    }
    
    return 0;
}