#include <iostream>
#include <vector>
#include <string>

class SpaceEntity {
protected:
	int id;
public:
	struct Position {
		float x;
		float y;
	};
	Position position;

	virtual void update() = 0;                                                  // Cap nhat trang thai/toa do cua thuc the
	virtual void draw() const = 0;                                              // Hien thi thong tin thuc the
	int getID() const;
	virtual ~SpaceEntity() {}
};

class SpaceSimulationEngine {
private:
	static SpaceSimulationEngine* instance;
	SpaceSimulationEngine() {}

	// Dam bao tinh duy nhat cua engine
	SpaceSimulationEngine(const SpaceSimulationEngine&) = delete;
	SpaceSimulationEngine& operator=(const SpaceSimulationEngine&) = delete;

	std::vector<SpaceEntity*> allEntities;
public:
	static SpaceSimulationEngine* getInstance();                                // Dang ky mot thuc the moi vao he thong mo phong
	void DeleteInstance();
	void registerEntity(SpaceEntity* entity);                                   // Duyet qua tat ca cac SpaceEntity da duoc dang ky va goi phuong thuc update() cung draw() cua chung
	void runSimulationCycle();
};





class Spacecraft;
class SpaceStructure;

// Personnel
class Commander {
private:
	std::string name;
	int credits;
	std::vector<Spacecraft*> fleetCraft;
	std::vector<SpaceStructure*> structures;

public:
	Commander(std::string name, int credits);
	friend std::ostream& operator<<(std::ostream& os, const Commander& cmd);
	std::string getName();
	void addStructure(SpaceStructure* structure);
	void addCraft(Spacecraft* craft);
	std::vector<SpaceStructure*> getStructures();
	std::vector<Spacecraft*> getCrafts();
	void moveTo(int id, float x, float y);                                          // Muon duy nhat 1 tau di chuyen
	void fleetmoveTo(float x, float y);                                             // Muon ca doan tau di chuyen
	void structureCommand();                                                        // Ra lenh cho mot cong trinh
	~Commander();
};







// Ships
class Spacecraft : public SpaceEntity {
protected:
	int hull;
	int speed;
	Commander* owner;
	std::string state;                                                           // 1. Dang dung yen | 2. Dang di chuyen
public:
	struct Skill {
		std::string name;
		int ep; // Energy Point
	};

	virtual Spacecraft* clone() const = 0;                                       // Prototype
	void moveTo(Position newPos);                                                // Cap nhat toa do di chuyen cua phi thuyen
	void setOwner(Commander* cmd);
};

class Fleet : public SpaceEntity { // Composite
private:
	std::vector<Spacecraft*> members;

public:
	void addCraft(Spacecraft* craft);
	void removeCraft(Spacecraft* craft);
	void update() override;
	void draw() const override;
	friend Fleet operator+(const Fleet& fleetA, const Fleet& fleetB);
};

class ScoutShip : public Spacecraft {
private:
	int totalEP;                                                                  // Energy Point
	std::vector<Skill> skills;
public:
	ScoutShip();
	ScoutShip(const ScoutShip& ss);
	Spacecraft* clone() const override;
	void update() override;
	void draw() const override;
	void useSkill(std::string name);                                              // Su dung chieu
	void upgrade();                                                               // Nang cap tau (Commander duoc chon nang cap EP hoac them chieu)
};

class FighterShip : public Spacecraft {
private:
	int totalEP; // Energy Point
	std::vector<Skill> skills;
public:
	FighterShip();
	FighterShip(const FighterShip& fs);
	Spacecraft* clone() const override;
	void update() override;
	void draw() const override;
	void useSkill(std::string name);                                              // Su dung chieu
	void upgrade();                                                               // Nang cap tau (Commander duoc chon nang cap EP hoac them chieu)
};





// Structures
class SpaceStructure : public SpaceEntity {
private:
	int hull;
	Commander* owner;
public:
	virtual Spacecraft* produceCraft() = 0;
};

class Shipyard : public SpaceStructure {
private:
	Spacecraft* craftPrototype;
public:
	std::vector<Spacecraft*> unownedSpaceCraft; // Luu tru nhung tau chua co chi huy so huu

public:
	Shipyard();
	void setPrototype(Spacecraft* proto);
	void update() override;
	void draw() const override;
	Spacecraft* produceCraft() override;
};