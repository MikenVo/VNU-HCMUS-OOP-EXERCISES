// Create 3 cars
// Get into a station
// Create a session -> Check a port

#include <iostream>
#include "ini.h"
using namespace std;

int main() {
    ElectricVehicle car1;
    ElectricVehicle car2;
    ElectricVehicle car3;

    cin >> car1;
    cout << "-----" << endl;
    cin >> car2;
    cout << "-----" << endl;
    cin >> car3;
    
    ChargingStation station;

    ChargingPort port1;
    ChargingPort port2;
    ChargingPort port3;


    return 0;
}