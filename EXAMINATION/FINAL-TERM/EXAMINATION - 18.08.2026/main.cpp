#include <iostream>
#include <vector>
#include <string>
#include "game.h"
using namespace std;

int main() {
    // Khởi tạo SpaceSimulationEngine (Kiểm tra Singleton)
    cout << "--- Initializing Space Simulation Engine ---\n";
    SpaceSimulationEngine *engine = SpaceSimulationEngine::getInstance();
    cout << "Engine instance at: " << engine << endl;
    SpaceSimulationEngine *anotherEngine = SpaceSimulationEngine::getInstance();
    cout << "Another engine instance at: " << anotherEngine << "\n\n";

    // Tạo chỉ huy và các nguyên mẫu phi thuyền (Kiểm tra Prototype)
    cout << "--- Setting up Commander and Prototypes ---\n";
    Commander cmd1("Commander Shepard", 50000);
    ScoutShip scoutPrototype;     // Nguyên mẫu tàu do thám
    FighterShip fighterPrototype; // Nguyên mẫu tàu chiến đấu

    // Chỉ huy xây xưởng đóng tàu (Kiểm tra Composition và Prototype)
    cout << "\n--- Commander builds a Shipyard ---\n";
    SpaceStructure *shipyard = new Shipyard();
    // Downcast để cấu hình prototype
    static_cast<Shipyard *>(shipyard)->setPrototype(&scoutPrototype);
    cmd1.addStructure(shipyard);
    cout << "Shipyard built and configured to produce Scout Ships.\n";

    // Xưởng tàu sản xuất phi thuyền (Kiểm tra Prototype)
    cout << "\n--- Shipyard produces Spacecrafts ---\n";
    Spacecraft *craft1 = cmd1.getStructures()[0]->produceCraft();
    Spacecraft *craft2 = cmd1.getStructures()[0]->produceCraft();
    if (craft1 && craft2)
    {
        cmd1.addCraft(craft1);
        cmd1.addCraft(craft2);
        cout << "2 Scout Ships produced from Shipyard using clone().\n";
    }

    // Tạo nhóm hạm đội (Kiểm tra Composite và Aggregation)
    cout << "\n--- Organizing a Fleet ---\n";
    Fleet fleet1;
    fleet1.addCraft(cmd1.getCrafts()[0]);
    fleet1.addCraft(cmd1.getCrafts()[1]);
    cout << "Fleet 1 created with 2 Scout Ships.\n";

    // Thêm hạm đội vào hệ thống mô phỏng (Kiểm tra đa hình)
    engine->registerEntity(&fleet1);
    cout << "\n--- Demonstrating Polymorphism via Simulation Loop ---\n";
    cout << "Running simulation cycle on entire fleet:\n";
    fleet1.update(); // Lệnh update sẽ được ủy quyền cho từng phi thuyền trong hạm đội

    // Kiểm tra nạp chồng toán tử
    cout << "\n--- Testing Operator Overloading ---\n";
    cout << "Commander status using overloaded << operator:\n";
    cout << cmd1 << endl; // In thông tin chỉ huy

    // Tạo hạm đội thứ 2 và hợp nhất
    Fleet fleet2;
    // Cấu hình xưởng tàu sản xuất loại tàu mới
    static_cast<Shipyard *>(shipyard)->setPrototype(&fighterPrototype);
    Spacecraft *craft3 = cmd1.getStructures()[0]->produceCraft();
    cmd1.addCraft(craft3);
    fleet2.addCraft(cmd1.getCrafts()[2]);
    Fleet combinedFleet = fleet1 + fleet2;
    cout << "Combined Fleet created using overloaded + operator.\n";
    cout << "Combined Fleet status:\n";
    combinedFleet.draw(); // Vẽ tất cả các phi thuyền trong hạm đội hợp nhất
    // Khi hàm main kết thúc, đối tượng cmd1 sẽ bị hủy.
    // Hàm hủy của Commander (~Commander) sẽ được gọi, có trách nhiệm giải phóng
    // bộ nhớ cho tất cả Spacecraft và SpaceStructure mà nó sở hữu.

    Armada armada;
    armada.addMember(&combinedFleet);
    armada.draw();

    cout << "\n--- Exiting main(), Commander destructor will be called. ---\n";
    return 0;
}