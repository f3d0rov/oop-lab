#pragma once

#include "inventory.hpp"


class Table : public Inventory {
	public:
		std::string material = "";
		Table (int number, std::string factory, std::string material);

		std::string str () const override;
};

class Chair : public Inventory {
	public:
		bool soft = false;
		bool adjustable = false;
		Chair(int number, std::string factory, bool soft, bool adjustable);

		std::string str () const override;
};

class Monitor : public Inventory {
	public:
		int colorDepth = 32;
		int resolutionWidth = 0;
		int resolutionHeight = 0;
		Monitor (int number, std::string factory, int resWidth, int resHeight);

		std::string str () const override;
};

class Computer : public Inventory {
	public:
		std::string processor = "";
		bool integratedGPU = true;
		Computer (int number, std::string factory, std::string processor, bool integratedGPU);

		std::string str() const override;
};

class Mouse : public Inventory {
	public:
		int dpiMin = 800, dpiMax = 3200;

		Mouse (int number, std::string factory, int dpiMin, int dpiMax);

		std::string str() const override;
};
