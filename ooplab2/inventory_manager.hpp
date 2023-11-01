#pragma once

#include <vector>
#include <memory>

#include "inventory.hpp"

template <class T, class ...Args>
class RandomInventoryGenerator {
	public:
		static Inventory *generateRandom (int number, size_t c) {
			if (c == 0) return T::template random (number);
			return RandomInventoryGenerator<Args...>::generateRandom (number, c - 1);
		}
};

template <class T>
class RandomInventoryGenerator<T> {
	public:
		static Inventory *generateRandom(int number, size_t c) {
			if (c == 0) return T::template random (number);
			throw std::logic_error ("RandomInventoryGenerator::generateRandom достигнута при `c` != 1");
		}
};

template <class ...Args>
Inventory *generateRandomOf (int number) {
	return RandomInventoryGenerator<Args...>::generateRandom (number, std::rand() % sizeof...(Args));
}

class InventoryManager {
		static int _counter;
		std::vector <Inventory *> _invs;


	public:
		~InventoryManager ();
		
		template <class T, class... Args>
		void emplace(Args... args) {
			this->_invs.push_back (
				dynamic_cast <Inventory *> (new T (this->_counter++, args...))
			);
		}

		template <class T>
		void pushRandom() {
			this->_invs.push_back (
				dynamic_cast <Inventory *> (generateRandom <T> (this->_counter++))
			);
		}

		template <class ...Args>
		void pushRandomOf () {
			this->_invs.push_back (
				generateRandomOf<Args...>(this->_counter++)
			);
		}

		void log (int n);
		void logAll ();
		void logFilterByType (std::string type);

		void assertInventoryHasFactoriesAndTypes ();
		void fixMissingFactoriesAndTypes ();
};
