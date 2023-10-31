
#include "inventory_manager.hpp"

int InventoryManager::_counter = 200001;

InventoryManager::~InventoryManager() {
	for (auto& i : this->_invs) {
		delete i;
	}
}

void InventoryManager::log (int count) {
	if (count > this->_invs.size()) count = this->_invs.size();
	for (int i = 0; i < count; i++) {
		std::cout << "[" << (i + 1) << "] " << *(this->_invs[i]) << std::endl;
	}

	std::cout << "����� �������: " << this->_invs.size() << std::endl << std::endl;
}

void InventoryManager::logAll() {
	this->log (this->_invs.size());
}

void InventoryManager::logFilterByType(std::string type) {
	std::cout << "������� � ����� '" << type << "': " << std::endl;
	int count = 0;

	for (auto& i : this->_invs) {
		if (i->getType() == type) {
			std::cout << "    " << *i << std::endl;
			count += 1;
		}
	}

	std::cout << "����� �������: " << count << std::endl;
}

void InventoryManager::assertInventoryHasFactoriesAndTypes() {
	for (auto& i : this->_invs) {
		if (i->factory == "") throw std::runtime_error ("����������� ���� `factory` � ������� Inventory");
		if (i->type == "") throw std::runtime_error("����������� ���� `type` � ������� Inventory");
	}
}

void InventoryManager::fixMissingFactoriesAndTypes () {
	try {
		assertInventoryHasFactoriesAndTypes ();
	} catch (std::exception &e) {
		for (auto& i : this->_invs) {
			if (i->factory == "") i->factory = "[�� �������������]";
			if (i->type == "") i->type = "[�� �������������]";
		}
	}
	try {
		assertInventoryHasFactoriesAndTypes ();
	} catch (std::exception & e) {
		throw std::logic_error ("InventoryManager::fixMissingFactoriesAndTypes �� ���� ��������� ������");
	}
}
