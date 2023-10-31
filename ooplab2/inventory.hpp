#pragma once

#include <iostream>
#include <string>
#include <vector>


template <class T>
T selectRandom(const std::vector<T>& vec) {
	return vec[std::rand() % vec.size()];
}

template <class T>
T *generateRandom (int num) {
	return T::template random (num);
}

class Inventory {
	private:
		int number;
		std::string type;
		std::string factory;

	public:
		friend class InventoryManager;

		Inventory (int number, std::string type, std::string factory);
		Inventory (const Inventory& lvalue);
		Inventory (Inventory&& rvalue);
		static Inventory *random(int number);
		virtual ~Inventory ();

		int getNumber () const;
		std::string getType () const;
		std::string getFactory () const;

		virtual std::string str() const;
		friend std::ostream& operator<< (std::ostream& os, const Inventory& inv);
};

std::ostream &operator<< (std::ostream &os, const Inventory &inv);