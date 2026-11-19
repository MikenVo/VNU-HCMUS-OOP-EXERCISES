#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ElectricVehicle {
    private:
        string plate; // Bien so xe
        string name;  // Ten chu xe
        int maxbat;   // Dung luong pin toi da
        float currentbat; // Phan tram pin hien tai

    public:
        ElectricVehicle(); // Construtor mac dinh
        ElectricVehicle(string plat, string dname, int maxb, float currentb); // Construtor co tham so

        ElectricVehicle& operator=(const ElectricVehicle& newcar);

        friend istream& operator>>(istream& is, ElectricVehicle& car); // Nhap
        friend ostream& operator<<(ostream& os, const ElectricVehicle& car); // Xuat

        ~ElectricVehicle(); // Destructor

        // Getter
        string GetPlate();
        string GetName();
        int GetMaxBattery();
        float GetCurrentBattery();

        // Setter
        void setPlate(string plat);
        void setName(string name);
        void setMaxBat(int MaxBat);
        void setCurrentBat(float CurrentBat);
};

class ChargingPort {
    private:
        string pcode; // Ma cong sac
        string ptype; // Loai cong sac
        int maxW; // Cong suat toi da
        bool state; // Trang thai dang ranh/dang dung

    public:
        ChargingPort(); // Constructor mac dinh
        ChargingPort(string pcode, string ptype, int maxW, bool state); // Construtor co tham so

        friend istream &operator>>(istream &is, ChargingPort &newport);       // Nhap
        friend ostream &operator<<(ostream &os, const ChargingPort&newport); // Xuat

        void setState(bool sta);

        ~ChargingPort(); // Destructor
};

class ChargingSession {
    private:
        string ctcode; // Ma luot sac
        ElectricVehicle car; // Thong tin xe dien
        int kWh; // So kWh da sac
        float price; // Don gia moi kWh
        ChargingPort* port;
        int numofports;

    public:
        ChargingSession();
        ChargingSession(string code, ElectricVehicle car, int ckWh, float price, int pnum);

        // Setter
        void setCTcode(string code);
        void setCar(ElectricVehicle car);
        void setkWh(int kWh);
        void setPrice(float sprice);
        void setNumberofPort(int num);

        ElectricVehicle getCarInfo();
        string getCTcode();

        void AddPort(ChargingPort port);
        void DeletePort();
        void updateportstates(ChargingPort& port);

        double calculateCost();
        bool isFastCharge();
        void finishSession();

        ~ChargingSession();
};

class ChargingStation {
    private:
        int numSessions;
        int capacity;
        ChargingSession* sessions;

    public:
        ChargingStation();
        ChargingStation(int num, int cap);

        ChargingStation& operator=(ChargingStation& ps);
        ChargingStation(const ChargingStation& ps);
        ~ChargingStation();

        ChargingStation& operator+=(int);
        ChargingStation& operator-=(int);

        void FindSession(string code, string platecode);
        void printSessions();
};