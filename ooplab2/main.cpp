
#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>

#include "inventory.hpp"
#include "inventory_manager.hpp"
#include "specific_classes.hpp"

#include "incapsulation.hpp"


#define INV_SIZE 100


int main () {
	setlocale (LC_ALL, "Russian");

	std::unique_ptr<InventoryManagerInterface> manager = std::make_unique <InventoryManagerImpl>();

	manager->emplace <Chair> (manager->takeNextCounter(), "", true, true);

	for (int i = 0; i < INV_SIZE; i++) 
		manager->push (generateRandomOf <BasicInventory, Table, Chair, Computer, Mouse, Monitor> ());

	auto inventory = manager->getAll();
	int count = 30;
	for (auto i : inventory) {
		std::cout << *i << std::endl;
		if (--count <= 0) break;
	}

	std::string type = "Монитор";
	std::cout << std::endl << "Фильтр по типу '" + type + "':" << std::endl;
	auto typeTest = manager->filterByType ("Монитор");
	for (auto i : typeTest) {
		std::cout << *i << std::endl;
	}

	std::cout << std::endl;

	manager->fixMissingFactoriesAndTypes();
	inventory = manager->getAll();
	count = 5;
	for (auto i: inventory) {
		std::cout << *i << std::endl;
		if (--count < 0) break;
	}

	return 0;
}
