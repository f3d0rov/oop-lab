
#include "inventory.hpp"

Inventory::Inventory (int number, std::string type, std::string factory):
number (number), type (type), factory (factory) {

}

Inventory::Inventory (const Inventory& lvalue):
number (lvalue.number), type (lvalue.type), factory (lvalue.factory) {

}

Inventory::Inventory (Inventory&& rvalue) {
	number = rvalue.number;
	rvalue.number = 0;
	type = std::move (rvalue.type);
	factory = std::move (rvalue.factory);
}

Inventory::~Inventory () {
	// ???
}

std::string Inventory::str () const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + ", произведен '" + this->factory + "'";
}

std::ostream& operator<< (std::ostream& os, const Inventory& inv) {
	os << inv.str();
	return  os;
}
