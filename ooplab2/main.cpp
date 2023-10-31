
#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>

#include "inventory.hpp"
#include "specific_classes.hpp"

#include "incapsulation.hpp"


#define INV_SIZE 100

void filterByTypeAndPrint(std::vector <Inventory *>& invs, std::string type) {
	std::cout << "Позиции с типом '" << type << "': " << std::endl;
	int count = 0;

	for (auto& i : invs) {
		if (i->type == type) {
			std::cout << "    " << *i << std::endl;
			count += 1;
		}
	}

	std::cout << "Всего позиций: " << count << std::endl;
}


Inventory* generateRandomInventory() {
	static int counter = 200001;

	std::vector <std::function <Inventory * (int)> > funcs = {
		generateRandom<Table>,
		generateRandom<Chair>,
		generateRandom<Monitor>,
		generateRandom<Computer>,
		generateRandom<Mouse>,
		generateRandom<Inventory>
	};

	int type = counter /*std::rand()*/ % (funcs.size());
	return funcs[type](++counter);
}

void testIncapsulation() {
	PublicChild pubC;
	ProtectedChild protC;
	PrivateChild privC;
	std::cout << std::endl;
}

int main () {
	setlocale (LC_ALL, "Russian");

	std::vector <Inventory *> invs;
	for (int i = 0; i < INV_SIZE; i++) invs.push_back(generateRandomInventory());
	for (int i = 0; i < (20 > INV_SIZE ? INV_SIZE : 20); i++) {
		std::cout << "[" << (i+1) << "] " << *invs[i] << std::endl;
	}
	std::cout << "Всего позиций: " << INV_SIZE << std::endl << std::endl;

	filterByTypeAndPrint (invs, "Монитор");
	for (auto& i : invs) {
		delete i;
	}
	return 0;
}
