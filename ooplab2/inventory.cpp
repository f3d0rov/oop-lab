
#include "inventory.hpp"

InventoryIface::~InventoryIface() {

}

std::ostream& operator<< (std::ostream& os, const InventoryIface &inv) {
	os << inv.str();
	return os;
}
