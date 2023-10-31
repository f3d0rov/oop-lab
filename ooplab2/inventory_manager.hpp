#pragma once

#include <vector>
#include <memory>

#include "inventory.hpp"

class InventoryManager {
		static int _counter;
		std::vector <Inventory *> _invs;


	public:
		~InventoryManager ();
		
		template <class T, class... Args>
		void emplace(Args... args) {
			this->_invs.push_back (
				dynamic_cast <Inventory *> (new T (_counter++, args...))
			);
		}

		template <class T>
		void pushRandom() {
			this->_invs.push_back (
				dynamic_cast <Inventory *> (generateRandom <T> (_counter++))
			);
		}

		void log (int n);
		void logAll ();
		void logFilterByType (std::string type);

		void assertInventoryHasFactoriesAndTypes ();
		void fixMissingFactoriesAndTypes ();
};
