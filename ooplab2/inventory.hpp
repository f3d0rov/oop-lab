#pragma once

#include <iostream>
#include <string>

class Inventory {
	public:
		int number;
		std::string type;
		std::string factory;

		Inventory (int number, std::string type, std::string factory);
		Inventory (const Inventory& lvalue);
		Inventory (Inventory&& rvalue);
		~Inventory ();

		virtual std::string str() const;
};

std::ostream& operator<< (std::ostream& os, const Inventory& inv);