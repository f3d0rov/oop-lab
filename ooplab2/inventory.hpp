#pragma once

#include <iostream>
#include <string>
#include <vector>


class InventoryIface {
	public:
		virtual ~InventoryIface();

		virtual int getNumber() const = 0;
		virtual std::string getType() const = 0;
		virtual std::string getFactory() const = 0;

		virtual void setNumber	(int n) = 0;
		virtual void setType	(std::string type) = 0;
		virtual void setFactory	(std::string factory) = 0;

		// virtual bool requiresNumber ();

		virtual std::string str() const = 0;
};


std::ostream& operator<< (std::ostream& os, const InventoryIface& inv);
