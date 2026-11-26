#include <iostream>
#include <vector>
#include <string>
#include "game.h"

// ===== Shipyard =====
Shipyard::Shipyard() {
	craftPrototype = nullptr;
}

void Shipyard::setPrototype(Spacecraft* proto) {
	craftPrototype = proto;
}

Spacecraft* Shipyard::produceCraft() {
	if (craftPrototype != nullptr) {
		std::cout << "[Shipyard] Produced a new spacecraft" << std::endl;
		Spacecraft* product = craftPrototype->clone();
		std::cout << "Do Commander want to upgrade the technology on this ship? (Y/N)" << std::endl;
		char choice; std::cin >> choice; std::cin.ignore(1000,'\n');

		if (choice == 'Y' || choice == 'y') {
		    std::cout << "- Available Technology Modules -" << std::endl;
		    std::cout << "1. Shield - Add 30 points into hull" << std::endl;
		    std::cout << "2. Warp Drive - Add 50 points into speed" << std::endl;
		    int subChoice;
		    std::cout << "Input your choice: " << std::endl;
		    std::cin >> subChoice; std::cin.ignore(1000,'\n');

		    if (!(std::cin >> subChoice)) {
		        std::cin.clear();
		        std::cin.ignore(1000, '\n');
		        std::cout << "Invalid input" << std::endl;
		    }
		    else {
		        std::cin.ignore(1000, '\n');

		        TechModule *newModule = nullptr;

		        if (subChoice == 1) {
		            newModule = new ShieldModule();
		        }
		        else if (subChoice == 2) {
		            newModule = new WarpDriveModule();
		        }
		        else {
		            std::cout << "Option not found" << std::endl;
		        }

		        if (newModule != nullptr) {
		            product->addTech(newModule);
		            newModule->getStatBoost(product);
		        }
		    }
		}
		else if (choice == 'N' || choice == 'n') {
		    std::cout << "No upgrade added" << std::endl;
		}
		else {
		    std::cout << "Invalid operation" << std::endl;
		}
		return product;
	}
	std::cout << "[Shipyard] Error: No prototype set" << std::endl;
	return nullptr;
}

void Shipyard::update() {

}

void Shipyard::draw() const {
	std::cout << "===== Shipyard " << id << " =====" << std::endl;
	std::cout << "1. Current Prototype: " << (craftPrototype ? "Active" : "None") << std::endl;
}


