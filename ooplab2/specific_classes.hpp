#pragma once

#include "inventory.hpp"


class BasicInventory : public InventoryIface {
private:
	int number;
	std::string type;
	std::string factory;

public:

	BasicInventory (int number, std::string type, std::string factory);
	BasicInventory (const BasicInventory& lvalue);
	BasicInventory (BasicInventory&& rvalue);

	static BasicInventory* random(int number);
	virtual ~BasicInventory();

	int getNumber() const override;
	std::string getType() const override;
	std::string getFactory() const override;

	void setNumber(int n) override;
	void setType(std::string type) override;
	void setFactory(std::string factory) override;

	virtual std::string str() const override;
};



template <class T>
T selectRandom(const std::vector<T>& vec) {
	return vec[std::rand() % vec.size()];
}

template <class T>
T* generateRandom(int num) {
	return T::template random(num);
}


template <class T, class ...Args>
class RandomInventoryGenerator {
public:
	static BasicInventory* generateRandom(int number, size_t c) {
		if (c == 0) return T::template random(number);
		return RandomInventoryGenerator<Args...>::generateRandom(number, c - 1);
	}
};

template <class T>
class RandomInventoryGenerator<T> {
public:
	static BasicInventory* generateRandom(int number, size_t c) {
		if (c == 0) return T::template random(number);
		throw std::logic_error("RandomInventoryGenerator::generateRandom достигнута при `c` != 1");
	}
};

template <class ...Args>
BasicInventory* generateRandomOf(int number = -1) {
	return RandomInventoryGenerator<Args...>::generateRandom(number, std::rand() % sizeof...(Args));
}



class Table : public BasicInventory {
	public:
		std::string material = "";
		Table (int number, std::string factory, std::string material);
		static Table *random (int number);
		~Table();

		std::string str () const override;
};


class Chair : public BasicInventory {
	public:
		bool soft = false;
		bool adjustable = false;
		Chair(int number, std::string factory, bool soft, bool adjustable);
		static Chair* random (int number);
		~Chair ();

		std::string str () const override;
};


class Monitor : public BasicInventory {
	public:
		int colorDepth = 32;
		int resolutionWidth = 0;
		int resolutionHeight = 0;
		Monitor (int number, std::string factory, int resWidth, int resHeight);
		static Monitor *random (int number);
		~Monitor ();

		std::string str () const override;
};


class Computer : public BasicInventory {
	public:
		std::string processor = "";
		bool integratedGPU = true;
		Computer (int number, std::string factory, std::string processor, bool integratedGPU);
		static Computer *random (int number);
		~Computer ();

		std::string str() const override;
};


class Mouse : public BasicInventory {
	public:
		int dpiMin = 800, dpiMax = 3200;

		Mouse (int number, std::string factory, int dpiMin, int dpiMax);
		static Mouse *random (int number);
		~Mouse ();

		std::string str() const override;
};
