
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

	InventoryManager manager;
	manager.emplace <Chair> ("", true, true);

	for (int i = 0; i < INV_SIZE; i++) 
		manager.pushRandomOf <Table, Chair, Monitor, Computer, Mouse, Inventory> ();
	manager.log (30);
	manager.logFilterByType("Монитор");
	manager.fixMissingFactoriesAndTypes();
	manager.log (5);

	return 0;
}
