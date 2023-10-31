#pragma once

#include "inventory.hpp"


class Table : public Inventory {
	public:
		std::string material = "";
		Table (int number, std::string factory, std::string material);
		static Table *random (int number);
		~Table();

		std::string str () const override;
};

class Chair : public Inventory {
	public:
		bool soft = false;
		bool adjustable = false;
		Chair(int number, std::string factory, bool soft, bool adjustable);
		static Chair* random (int number);
		~Chair ();

		std::string str () const override;
};

class Monitor : public Inventory {
	public:
		int colorDepth = 32;
		int resolutionWidth = 0;
		int resolutionHeight = 0;
		Monitor (int number, std::string factory, int resWidth, int resHeight);
		static Monitor *random (int number);
		~Monitor ();

		std::string str () const override;
};

class Computer : public Inventory {
	public:
		std::string processor = "";
		bool integratedGPU = true;
		Computer (int number, std::string factory, std::string processor, bool integratedGPU);
		static Computer *random (int number);
		~Computer ();

		std::string str() const override;
};

class Mouse : public Inventory {
	public:
		int dpiMin = 800, dpiMax = 3200;

		Mouse (int number, std::string factory, int dpiMin, int dpiMax);
		static Mouse *random (int number);
		~Mouse ();

		std::string str() const override;
};
