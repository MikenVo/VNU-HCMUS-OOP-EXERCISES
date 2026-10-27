#include <iostream>
#include <vector>
#include <string>
#include "game.h"

// ===== Shipyard =====
Shipyard::Shipyard() {
    craftPrototype = nullptr;
}

void Shipyard::setPrototype(Spacecraft *proto) {
    craftPrototype = proto;
}

Spacecraft *Shipyard::produceCraft() {
    if (craftPrototype != nullptr) {
        std::cout << "[Shipyard] Produced a new spacecraft" << std::endl;
        return craftPrototype->clone();
    }
    std::cout << "[Shipyard] Error: No prototype set" << std::endl;
    return nullptr;
}

void Shipyard::update() {
    // Xử lý logic vận hành theo chu kỳ của xưởng
}

void Shipyard::draw() const {
    std::cout << "===== Shipyard " << id << " =====" << std::endl;
    std::cout << "1. Current Prototype: " << (craftPrototype ? "Active" : "None") << std::endl;
    std::cout << "2. Unowned crafts: " << unownedSpaceCraft.size() << std::endl;
}