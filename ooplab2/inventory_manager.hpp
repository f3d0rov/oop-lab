#pragma once

#include <vector>
#include <memory>
#include <functional>

#include "inventory.hpp"


class InventoryManagerInterface {
	public:
		~InventoryManagerInterface();

		virtual int takeNextCounter() = 0;
		

		virtual void push (InventoryIface *) = 0;
		template <class T, class... Args>
		void emplace(Args... args) {
			this->push (
				dynamic_cast <InventoryIface*> (new T(args...))
			);
		}


		virtual std::vector <const InventoryIface *> getAll() = 0;
		virtual std::vector <const InventoryIface *> filterBy(std::function <bool(InventoryIface*)> filter) = 0;
		std::vector <const InventoryIface *> filterByType(std::string type);


		virtual void assertInventoryHasFactoriesAndTypes() = 0;
		virtual void fixMissingFactoriesAndTypes() = 0;
};


class InventoryManagerImpl: public InventoryManagerInterface {
		static int _counter;
		std::vector <InventoryIface *> _invs;

	public:
		~InventoryManagerImpl();

		int takeNextCounter();

		void push (InventoryIface *inv) override;

		std::vector <const InventoryIface *> getAll () override;
		std::vector <const InventoryIface *> filterBy (std::function <bool(InventoryIface*)> filter) override;

		void assertInventoryHasFactoriesAndTypes () override;
		void fixMissingFactoriesAndTypes () override;
};

