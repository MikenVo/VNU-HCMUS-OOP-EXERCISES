#include <iostream>
#include <vector>
#include <string>
#include "game.h"

std::string ShieldModule::getTechName() const {
    return name;
}

std::string WarpDriveModule::getTechName() const {
    return name;
}

ShieldModule::ShieldModule() : TechModule(0, "Shield") {}

WarpDriveModule::WarpDriveModule() : TechModule(1, "Warp drive") {}

// ShieldModule::ShieldModule() {
//     id = 0;
//     name = "Shield";
// }

// WarpDriveModule::WarpDriveModule() {
//     id = 1;
//     name = "Warp Drive";
// }

void ShieldModule::getStatBoost(Spacecraft*& craft) const {
    int hull = craft->getHull() + 30;
    craft->SetHull(hull);
}

void WarpDriveModule::getStatBoost(Spacecraft*& craft) const {
    int speed = craft->getSpeed() + 50;
    craft->SetSpeed(speed);
}