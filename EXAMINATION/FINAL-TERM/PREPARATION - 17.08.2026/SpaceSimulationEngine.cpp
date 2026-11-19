#include <iostream>
#include <vector>
#include <string>
#include "game.h"

int SpaceEntity::getID() const {
    return id;
}

SpaceSimulationEngine* SpaceSimulationEngine::instance = nullptr;

SpaceSimulationEngine* SpaceSimulationEngine::getInstance() {
    if (instance == nullptr) {
        instance = new SpaceSimulationEngine();
    }
    return instance;
}

void SpaceSimulationEngine::DeleteInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void SpaceSimulationEngine::registerEntity(SpaceEntity* entity) {
    if (entity != nullptr) {
        allEntities.push_back(entity);
        std::cout << "The entity has been added into the simulation successfully" << std::endl;
        return;
    }
    std::cout << "The entity has been added into the simulation unsuccessfully" << std::endl;
}

void SpaceSimulationEngine::runSimulationCycle() {
    std::cout << "===== Running simulation =====" << std::endl;
    int numofentities = allEntities.size();                                          // Chot so luong thuc the truoc khi chay simulation
    for (int i = 0; i < numofentities; i++) {
        allEntities[i]->update();
        allEntities[i]->draw();
    }
}