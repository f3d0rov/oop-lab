
#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>

#include "inventory.hpp"
#include "inventory_manager.hpp"
#include "specific_classes.hpp"

#include "incapsulation.hpp"


#define INV_SIZE 100

void generateRandomInventoryForManager (InventoryManager &im) {
	static int counter = 200001;

	std::vector <std::function <void()>> funcs = {
		std::bind(&InventoryManager::pushRandom<Table>, &im),
		std::bind(&InventoryManager::pushRandom<Chair>, &im),
		std::bind(&InventoryManager::pushRandom<Monitor>, &im),
		std::bind(&InventoryManager::pushRandom<Computer>, &im),
		std::bind(&InventoryManager::pushRandom<Mouse>, &im),
		std::bind(&InventoryManager::pushRandom<Inventory>, &im)
	};

	int type = counter /*std::rand()*/ % (funcs.size());
	funcs[type]();
}

void testIncapsulation() {
	PublicChild pubC;
	ProtectedChild protC;
	PrivateChild privC;
	std::cout << std::endl;
}

int main () {
	setlocale (LC_ALL, "Russian");

	InventoryManager manager;
	manager.emplace <Chair> ("", true, true);

	for (int i = 0; i < INV_SIZE; i++) generateRandomInventoryForManager (manager);
	manager.log (10);
	manager.logFilterByType("Монитор");
	manager.fixMissingFactoriesAndTypes();
	manager.log (10);

	return 0;
}
