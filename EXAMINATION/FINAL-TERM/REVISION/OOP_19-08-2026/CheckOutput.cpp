#include <iostream>
#include <string>

using namespace std;

class PhysicalEntity {
protected:
    string name;

public:
    PhysicalEntity(string n) : name(n) {
        cout << "Entity constructor: " << name << endl;
    }

    virtual void show() const {
        cout << "Physical entity: " << name << endl;
    }

    virtual ~PhysicalEntity() {
        cout << "Entity destructor: " << name << endl;
    }
};

class Particle : public PhysicalEntity {
private:
    double mass;

public:
    Particle(string n, double m) :
        PhysicalEntity(n), mass(m) {
        cout << "Particle constructor: " << name << endl;
    }

    void show() const override {
        cout << name << ": particle, mass = " << mass << " kg" << endl;
    }

    ~Particle() override {
        cout << "Particle destructor: " << name << endl;
    }
};

class Wave : public PhysicalEntity {
private:
    double frequency;

public:
    Wave(string n, double f) :
        PhysicalEntity(n), frequency(f) {
        cout << "Wave constructor: " << name << endl;
    }

    void show() const override {
        cout << name << ": wave, frequency = " << frequency << " Hz" << endl;
    }

    ~Wave() override {
        cout << "Wave destructor: " << name << endl;
    }
};

class Field : public PhysicalEntity {
private:
    double strength;

public:
    Field(string n, double s) :
        PhysicalEntity(n), strength(s) {
        cout << "Field constructor: " << name << endl;
    }

    void show() const override {
        cout << name << ": field, strength = " << strength << " N/C" << endl;
    }

    ~Field() override {
        cout << "Field destructor: " << name << endl;
    }
};

int main() {
    Particle puck("Puck", 0.20);
    PhysicalEntity *entity = &puck;
    entity->show();
    return 0;
}

/*
Output:
Entity constructor: Puck
Particle constructor: Puck
Physical entity: Puck
Entity destructor: Puck
Particle destructor: Puck
*/