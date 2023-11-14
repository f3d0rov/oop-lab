
#include "specific_classes.hpp"



BasicInventory::BasicInventory(int number, std::string type, std::string factory) :
	number(number), type(type), factory(factory) {

}

BasicInventory::BasicInventory (const BasicInventory& lvalue) :
	number(lvalue.number), type(lvalue.type), factory(lvalue.factory) {

}

BasicInventory::BasicInventory (BasicInventory&& rvalue) {
	number = rvalue.number;
	rvalue.number = 0;
	type = std::move(rvalue.type);
	factory = std::move(rvalue.factory);
}

BasicInventory* BasicInventory::random (int number) {
	const std::vector <std::string> types = { "�������", "����" };
	const std::vector <std::string> factories = { "��� \"������\"", "��� \"�������\"", "��� \"�����\"", "��� \"�������\"" };
	return new BasicInventory (number, selectRandom(types), selectRandom(factories));
}

BasicInventory::~BasicInventory() {
	// ???
}

int BasicInventory::getNumber() const {
	return this->number;
}

std::string BasicInventory::getType() const {
	return this->type;
}

std::string BasicInventory::getFactory() const {
	return this->factory;
}


void BasicInventory::setNumber (int n) {
	this->number = n;
}

void BasicInventory::setType (std::string type) {
	this->type = type;
}


void BasicInventory::setFactory (std::string factory) {
	this->factory = factory;
}


std::string BasicInventory::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + ", ���������� '" + this->factory + "'";
}





Table::Table (int number, std::string factory, std::string material):
	BasicInventory(number, "����", factory), material (material) {

}

Table* Table::random(int number) {
	const std::vector <std::string> tableFactories = { "IKEA", "Table Factory(c)", "��� ���������������" };
	const std::vector <std::string> tableMaterials = { "������", "������", "������" };

	return new Table(number, selectRandom(tableFactories), selectRandom(tableMaterials));
}

Table::~Table() {

}

std::string Table::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory() + "', ��������: " + this->material;
}





Chair::Chair (int number, std::string factory, bool soft, bool adjustable):
BasicInventory (number, "����", factory), soft (soft), adjustable (adjustable) {

}

Chair *Chair::random (int number) {
	const std::vector <std::string> chairFactories = { "IKEA", "Chair Factory(c)", "��� ���������������" };
	return new Chair(number, selectRandom(chairFactories), std::rand() % 2, std::rand() % 2);
}

Chair::~Chair() {

}

std::string Chair::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory() + "', "
		+ (this->adjustable ? "������������" : "�� ������������") + ", " + (this->soft ? "� ������ ���������" : "� ������� ���������");
}





Monitor::Monitor(int number, std::string factory, int resWidth, int resHeight):
BasicInventory (number, "�������", factory), resolutionHeight (resHeight), resolutionWidth (resWidth) {

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
BasicInventory (number, "���������", factory), processor (processor), integratedGPU (integratedGPU) {

}

Computer* Computer::random (int number) {
	const std::vector <std::string> computerFactories = { "DELL", "Asus", "Acer" };
	const std::vector <std::string> processors = { "AMD", "Intel", "�������" };
	return new Computer(number, selectRandom(computerFactories), selectRandom(processors), std::rand() % 2);
}

Computer::~Computer() {

}

std::string Computer::str() const {
	return std::string("[") + std::to_string(this->getNumber()) + "] " + this->getType() + " '" + this->getFactory()
		+ "', ���������: " + this->processor + ", " + (this->integratedGPU ? "���������� ����������" : "���������� ����������");
}




Mouse::Mouse(int number, std::string factory, int dpiMin, int dpiMax):
BasicInventory (number, "������������ ����", factory), dpiMin (dpiMin), dpiMax (dpiMax) {

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
		+ "', DPI �� " + std::to_string (this->dpiMin) + " �� " + std::to_string (this->dpiMax);
}
