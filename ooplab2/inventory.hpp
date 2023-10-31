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
	public:
		int number;
		std::string type;
		std::string factory;

		Inventory (int number, std::string type, std::string factory);
		Inventory (const Inventory& lvalue);
		Inventory (Inventory&& rvalue);
		static Inventory *random(int number);
		~Inventory ();

		virtual std::string str() const;
		friend std::ostream& operator<< (std::ostream& os, const Inventory& inv);
};

std::ostream &operator<< (std::ostream &os, const Inventory &inv);