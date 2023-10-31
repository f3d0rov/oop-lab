
#include "specific_classes.hpp"

Table::Table (int number, std::string factory, std::string material):
Inventory (number, "Стол", factory), material (material) {

}

Table* Table::random(int number) {
	const std::vector <std::string> tableFactories = { "IKEA", "Table Factory(c)", "ООО Деревообработка" };
	const std::vector <std::string> tableMaterials = { "Дерево", "Стекло", "Камень" };

	return new Table(number, selectRandom(tableFactories), selectRandom(tableMaterials));
}

Table::~Table() {

}

std::string Table::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory() + "', материал: " + this->material;
}



Chair::Chair (int number, std::string factory, bool soft, bool adjustable):
Inventory (number, "Стул", factory), soft (soft), adjustable (adjustable) {

}

Chair *Chair::random (int number) {
	const std::vector <std::string> chairFactories = { "IKEA", "Chair Factory(c)", "ООО Деревообработка" };
	return new Chair(number, selectRandom(chairFactories), std::rand() % 2, std::rand() % 2);
}

Chair::~Chair() {

}

std::string Chair::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory() + "', "
		+ (this->adjustable ? "регулируемый" : "не регулируемый") + ", " + (this->soft ? "с мягким покрытием" : "с твердым покрытием");
}


Monitor::Monitor(int number, std::string factory, int resWidth, int resHeight):
Inventory (number, "Монитор", factory), resolutionHeight (resHeight), resolutionWidth (resWidth) {

}

Monitor* Monitor::random (int number) {
	const std::vector <std::string> monitorFactories = { "DELL", "Asus", "LG" };
	return new Monitor(number, selectRandom(monitorFactories), std::rand() % 4096, std::rand() % 4096);
}

Monitor::~Monitor() {

}

std::string Monitor::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory() + "', "
		+ std::to_string(this->resolutionWidth) + "x" + std::to_string(this->resolutionHeight);
}

Computer::Computer(int number, std::string factory, std::string processor, bool integratedGPU):
Inventory (number, "Компьютер", factory), processor (processor), integratedGPU (integratedGPU) {

}

Computer* Computer::random (int number) {
	const std::vector <std::string> computerFactories = { "DELL", "Asus", "Acer" };
	const std::vector <std::string> processors = { "AMD", "Intel", "Эльбрус" };
	return new Computer(number, selectRandom(computerFactories), selectRandom(processors), std::rand() % 2);
}

Computer::~Computer() {

}

std::string Computer::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory()
		+ "', процессор: " + this->processor + ", " + (this->integratedGPU ? "встроенная видеокарта" : "дискретная видеокарта");
}

Mouse::Mouse(int number, std::string factory, int dpiMin, int dpiMax):
Inventory(number, "Компьютерная мышь", factory), dpiMin (dpiMin), dpiMax (dpiMax) {

}

Mouse *Mouse::random(int number) {
	const std::vector <std::string> mouseFactories = { "Microsoft", "Apple", "Dell", "Digma" };
	int minDpi = 400 + std::rand() % 3200;
	return new Mouse(number, selectRandom(mouseFactories), minDpi, minDpi + std::rand() % 3200);
}

Mouse::~Mouse() {

}

std::string Mouse::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory()
		+ "', DPI от " + std::to_string (this->dpiMin) + " до " + std::to_string (this->dpiMax);
}
