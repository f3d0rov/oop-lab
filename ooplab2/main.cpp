
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

template <class T>
T selectRandom(const std::vector<T>& vec) {
	return vec[std::rand() % vec.size()];
}

Inventory *generateRandomInv(int num, std::vector <std::string>& types, std::vector <std::string>& factories) {
	return new Inventory(num, selectRandom(types), selectRandom(factories));
}

Table* generateRandomTable (int num) {
	const std::vector <std::string> tableFactories = { "IKEA", "Table Factory(c)", "ООО Деревообработка" };
	const std::vector <std::string> tableMaterials = { "Дерево", "Стекло", "Камень" };

	return new Table(num, selectRandom(tableFactories), selectRandom(tableMaterials));
}

Chair* generateRandomChair (int num) {
	const std::vector <std::string> chairFactories = { "IKEA", "Chair Factory(c)", "ООО Деревообработка" };
	return new Chair (num, selectRandom (chairFactories), std::rand() % 2, std::rand() % 2);
}

Monitor* generateRandomMonitor (int num) {
	const std::vector <std::string> monitorFactories = { "DELL", "Asus", "LG" };
	return new Monitor (num, selectRandom (monitorFactories), std::rand() % 4096, std::rand() % 4096);
}

Computer* generateRandomComputer (int num) {
	const std::vector <std::string> computerFactories = { "DELL", "Asus", "Acer" };
	const std::vector <std::string> processors = { "AMD", "Intel", "Эльбрус" };
	return new Computer(num, selectRandom(computerFactories), selectRandom (processors), std::rand() % 2);
}

Mouse* generateRandomMouse (int num) {
	const std::vector <std::string> mouseFactories = { "Microsoft", "Apple", "Dell", "Digma" };
	int minDpi = 400 + std::rand() % 3200;
	return new Mouse(num, selectRandom (mouseFactories), minDpi, minDpi + std::rand() % 3200);
}

Inventory* generateRandomInventory(std::vector <std::string>& types, std::vector <std::string>& factories) {
	static int counter = 200001;

	std::vector <std::function <Inventory * (int)> > funcs = {
		generateRandomTable,
		generateRandomChair,
		generateRandomMonitor,
		generateRandomComputer,
		generateRandomMouse
	};

	int type = counter /*std::rand()*/ % (funcs.size() + 1);
	if (type == 0) return generateRandomInv(counter++, types, factories);
	return funcs[type - 1](++counter);
}

void testIncapsulation() {
	PublicChild pubC;
	ProtectedChild protC;
	PrivateChild privC;
	std::cout << std::endl;
}

int main () {
	setlocale (LC_ALL, "Russian");
	std::vector <std::string> types = { "Табурет", "Шкаф" };
	std::vector <std::string> factories = { "ООО \"Мебель\"", "ООО \"Фабрика\"", "ЗАО \"Завод\"", "ОАО \"Медведь\"" };

	std::vector <Inventory *> invs;
	for (int i = 0; i < INV_SIZE; i++) invs.push_back(generateRandomInventory(types, factories));
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
