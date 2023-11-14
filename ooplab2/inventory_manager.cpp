
#include "inventory_manager.hpp"


InventoryManagerInterface::~InventoryManagerInterface() {

}

std::vector <const InventoryIface *> InventoryManagerInterface::filterByType (std::string type) {
	return this->filterBy([type](InventoryIface* i) -> bool { return i->getType() == type; });
}




int InventoryManagerImpl::_counter = 200001;


InventoryManagerImpl::~InventoryManagerImpl() {
	for (auto& i : this->_invs) {
		delete i;
	}
}

int InventoryManagerImpl::takeNextCounter() {
	return this->_counter++;
}


void InventoryManagerImpl::push (InventoryIface* inv) {
	if (inv->getNumber() < 0) inv->setNumber (this->takeNextCounter());
	this->_invs.push_back (inv);
}

std::vector <const InventoryIface *> InventoryManagerImpl::getAll () {
	return std::vector <const InventoryIface*> (this->_invs.begin(), this->_invs.end());
}

std::vector <const InventoryIface *> InventoryManagerImpl::filterBy (std::function <bool(InventoryIface*)> filter) {
	std::vector <const InventoryIface *> results{};
	for (auto i: this->_invs) {
		if (filter(i)) results.push_back (i);
	}
	return results;
}



void InventoryManagerImpl::assertInventoryHasFactoriesAndTypes() {
	for (auto& i : this->_invs) {
		if (i->getFactory() == "") throw std::runtime_error ("Отсутствует поле `factory` у объекта Inventory");
		if (i->getType() == "") throw std::runtime_error("Отсутствует поле `type` у объекта Inventory");
	}
}

void InventoryManagerImpl::fixMissingFactoriesAndTypes () {
	try {
		assertInventoryHasFactoriesAndTypes ();
	} catch (std::exception &e) {
		for (auto& i : this->_invs) {
			if (i->getFactory() == "") i->setFactory ("[На расследовании]");
			if (i->getType() == "") i->setType ("[На расследовании]");
		}
	}
	try {
		assertInventoryHasFactoriesAndTypes ();
	} catch (std::exception & e) {
		throw std::logic_error ("InventoryManager::fixMissingFactoriesAndTypes не смог исправить ошибки");
	}
}

