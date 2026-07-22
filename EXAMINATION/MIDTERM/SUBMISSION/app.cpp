#include <iostream>
#include <string>
#include "ini.h"
using namespace std;

// =====Electric vehicle=====
// -structors
ElectricVehicle::ElectricVehicle() {
    plate = "";
    name = "";
    maxbat = 0;
    currentbat = 0;
}

ElectricVehicle::ElectricVehicle(string plat, string dname, int maxb, float currentb) {
    plate = plat;
    name = dname;
    maxbat = maxb;
    currentbat = currentb;
}

ElectricVehicle& ElectricVehicle::operator=(const ElectricVehicle& newcar) {
    if (this == &newcar) {
        return *this;
    }

    this->plate = newcar.plate;
    this->name = newcar.name;
    this->maxbat = newcar.maxbat;
    this->currentbat = newcar.currentbat;

    return *this;
}

ElectricVehicle::~ElectricVehicle() {
    cout << "Delete complete" << endl;
}

istream& operator>>(istream& is, ElectricVehicle& car) {
    cout << "Input the plate number: ";
    is >> car.plate;
    cout << "Input the driver's name: ";
    is >> car.name;
    cout << "Input the car's maximum battery: ";
    is >> car.maxbat;
    cout << "Input the car's current percentage of battery: ";
    is >> car.currentbat;

    return is;
}

ostream& operator<<(ostream& os, const ElectricVehicle& car) {
    os << "----Information----" << endl;
    os << "1. Driver's name: " << car.name << endl;
    os << "2. Plate number: " << car.plate << endl;
    os << "3. Maximum battery: " << car.maxbat << endl;
    os << "4. Current battery: " << car.currentbat << "%" << endl;

    return os;
}

// Getter
string ElectricVehicle::GetPlate() {
    return plate;
}

string ElectricVehicle::GetName() {
    return name;
}

int ElectricVehicle::GetMaxBattery() {
    return maxbat;
}

float ElectricVehicle::GetCurrentBattery() {
    return currentbat;
}

// Setter
void ElectricVehicle::setPlate(string plat) {
    this->plate = plat;
}

void ElectricVehicle::setName(string name) {
    this->name = name;
}

void ElectricVehicle::setMaxBat(int MaxBat) {
    this->maxbat = MaxBat;
}

void ElectricVehicle::setCurrentBat(float CurrentBat) {
    this->currentbat = CurrentBat;
}




// ===== Charging Port =====
// -structors
ChargingPort::ChargingPort() {
    pcode = "P01";
    ptype = "Standard charge";
    maxW = 50;
    bool state = false; // No car is using the port
}

ChargingPort::ChargingPort(string pccode, string pctype, int maxcW, bool cstate) {
    pcode = pccode;
    ptype = pctype;
    maxW = maxcW;
    state = cstate;
}

ChargingPort::~ChargingPort() {
    cout << "Port deletion complete" << endl;
}

void ChargingPort::setState(bool sta) {
    this->state = sta;
}





// ===== Charging Session =====
ChargingSession::ChargingSession() {
    ctcode = "LS01";
    int kWh = 0;
    float price = 1;
    port = nullptr;
}

ChargingSession::ChargingSession(string code, ElectricVehicle newcar, int ckWh, float cprice, int pnum) {
    ctcode = code;
    car = newcar;
    kWh = ckWh;
    price = cprice;
    numofports = pnum;
    port = new ChargingPort[pnum]();
}

void ChargingSession::AddPort(ChargingPort newport) {
    ChargingPort* newports = new ChargingPort[numofports + 1];
    for (int i = 0; i < numofports; i++) {
        newports[i] = port[i];
    }

    newports[numofports] = newport;
    delete[] port;

    port = newports;

    numofports++;
}

void ChargingSession::setCTcode(string code) {
    this->ctcode = code;
}

void ChargingSession::setCar(ElectricVehicle newcar) {
    this->car = newcar;
}

void ChargingSession::setkWh(int ckWh) {
    this->kWh = ckWh;
}

void ChargingSession::setPrice(float sprice) {
    this->price = sprice;
}

void ChargingSession::setNumberofPort(int num) {
    this->numofports = num;
}

string ChargingSession::getCTcode() {
    return ctcode;
}

ElectricVehicle ChargingSession::getCarInfo() {
    return car;
}

ChargingSession::~ChargingSession() {
    delete[] port;
}




// ===== Charging Station =====
ChargingStation::ChargingStation() {
    numSessions = 0;
    capacity = 10;
    sessions = nullptr;
}

ChargingStation::ChargingStation(int num, int cap) {
    numSessions = num;
    capacity = cap;
    sessions = new ChargingSession[numSessions];
}

ChargingStation& ChargingStation::operator=(ChargingStation& ps) {
    if (this == &ps) {
        return *this;
    }

    delete[] this->sessions;

    this->numSessions = ps.numSessions;
    this->capacity = ps.capacity;
    
    ChargingSession* temp = new ChargingSession[numSessions];
    for (int i = 0; i < numSessions; i++) {
        temp[i] = ps.sessions[i];
    }
    this->sessions = temp;

    return *this;
}

ChargingStation::ChargingStation(const ChargingStation& ps) {
    this->numSessions = ps.numSessions;
    this->capacity = ps.capacity;

    ChargingSession *temp = new ChargingSession[numSessions];
    for (int i = 0; i < numSessions; i++) {
        temp[i] = ps.sessions[i];
    }
    this->sessions = temp;
}

ChargingStation::~ChargingStation() {
    delete[] sessions;
}



void ChargingStation::FindSession(string code, string platecode) {
    for (int i = 0; i < numSessions; i++) {
        if (sessions[i].getCarInfo().GetPlate() == platecode) {
            cout << "The car is charging at session " << i + 1 << endl;
        }
    }
}

