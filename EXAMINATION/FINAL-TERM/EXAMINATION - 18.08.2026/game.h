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






class TechModule {
	protected:
		int id;
		std::string name;
	public:
		TechModule(int id, const std::string &name) : id(id), name(name) {}
		virtual std::string getTechName() const = 0;
		virtual void getStatBoost(Spacecraft*& craft) const = 0;
		virtual ~TechModule() {};
};

class ShieldModule : public TechModule { // Tang giap
	public:
		ShieldModule();
		std::string getTechName() const override;
		void getStatBoost(Spacecraft*& craft) const override; // Se tang giap cho tau;
};

class WarpDriveModule : public TechModule { // Tang toc do di chuyen
	public:
		WarpDriveModule();
		std::string getTechName() const override;
		void getStatBoost(Spacecraft*& craft) const override;
};

// Ships
class Spacecraft : public SpaceEntity {
protected:
	int hull;
	int speed;
	Commander* owner;
	std::string state;                                                           // 1. Dang dung yen | 2. Dang di chuyen
	std::vector<TechModule *> tech;
public:
	struct Skill {
		std::string name;
		int ep; // Energy Point
	};

	virtual Spacecraft* clone() const = 0;                                       // Prototype
	void moveTo(Position newPos);                                                // Cap nhat toa do di chuyen cua phi thuyen
	void setOwner(Commander* cmd);
	// virtual void getOverallStrength() const = 0; // In ra nang luc tong the cua mot tau
	void addTech(TechModule* newTech);
	std::vector<TechModule*> getTechList();
	int getHull() const;
	int getSpeed() const;
	void SetHull(int newHull);
	void SetSpeed(int newSpeed);
	virtual ~Spacecraft() {};
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
	~ScoutShip();
};

class Armada : public SpaceEntity {
	private:
		std::vector<SpaceEntity*> members;
	public:
		void update() override;
		void draw() const override;
		void addMember(SpaceEntity* SE);
		~Armada();
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
	~FighterShip();
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
	Shipyard();
	void setPrototype(Spacecraft* proto);
	void update() override;
	void draw() const override;
	Spacecraft* produceCraft() override;
};



























/* ============================================================================
 * TỔNG HỢP CÁC QUAN HỆ OOP & QUY CHUẨN VẼ UML CLASS DIAGRAM
 * ============================================================================
 *
 * 1. QUY TẮC KHUNG CLASS (3 NGĂN):
 *  - Ngăn 1 (Tên): PascalCase (In nghiêng nếu là Abstract Class / Interface).
 *  - Ngăn 2 (Thuộc tính): [visibility] name: type = default (Gạch chân nếu static).
 *  - Ngăn 3 (Phương thức): [visibility] name(param: type): returnType (In nghiêng nếu pure virtual).
 *  - Visibility: (+) public | (-) private | (#) protected | (~) package
 *
 * 2. CÁC QUAN HỆ TRONG OOP & KÝ HIỆU ĐƯỜNG NỐI UML:
 *
 * 1) DEPENDENCY (Phụ thuộc - "Uses a"):
 *  - Bản chất: A dùng B tạm thời làm tham số hàm, biến cục bộ. Không lưu trữ B.
 *  - UML: Nét đứt, mũi tên đơn [- - >] (A - - > B : A phụ thuộc B).
 *  - Ví dụ: TelemetryViewer::render(TelemetryPacket pkt)
 *
 * 2) ASSOCIATION (Liên kết - "Relates to"):
 *  - Bản chất: A giữ con trỏ/tham chiếu đến B. Cả hai có vòng đời độc lập.
 *  - UML: Nét liền, mũi tên đơn [──>] (1 chiều) hoặc không đầu [──] (2 chiều).
 *  - Ví dụ: Driver ──> SteeringWheel
 *
 * 3) AGGREGATION (Chứa lỏng / Thu nạp - "Has a"):
 *  - Bản chất: Quan hệ Whole - Part lỏng lẻo. Whole bị hủy, Part VẪN TỒN TẠI.
 *  - UML: Nét liền, hình thoi RỖNG ở phía Whole [Whole ◇── Part].
 *  - Ví dụ: PitCrew ◇── Mechanic* (Đội giải tán, thợ máy vẫn còn)
 *
 * 4) COMPOSITION (Chứa chặt / Hợp thành - "Part of"):
 *  - Bản chất: Quan hệ Whole - Part sống chết cùng nhau. Whole hủy -> Part HỦY THEO.
 *  - UML: Nét liền, hình thoi ĐẶC ở phía Whole [Whole ◆── Part].
 *  - Ví dụ: F1Car ◆── InternalCombustionEngine (Xe bị hủy, động cơ mất)
 *
 * 5) INHERITANCE / GENERALIZATION (Kế thừa - "Is a"):
 *  - Bản chất: Class con tái sử dụng và mở rộng logic từ Class cha.
 *  - UML: Nét liền, tam giác RỖNG [Derived ──▷ Base] (Trỏ từ Con lên Cha).
 *  - Ví dụ: FerrariSF25 ──▷ RaceCar
 *
 * 6) REALIZATION (Hiện thực hóa - "Can do"):
 *  - Bản chất: Class cài đặt các hàm thuần ảo do Interface định nghĩa.
 *  - UML: Nét đứt, tam giác RỖNG [Class - - ▷ Interface] (Trỏ về Interface).
 *  - Ví dụ: HybridPowertrain - - ▷ IEnergyRecoverySystem
 * ============================================================================ */