
#include "specific_classes.hpp"

Table::Table (int number, std::string factory, std::string material):
Inventory (number, "����", factory), material (material) {

}

std::string Table::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory + "', ��������: " + this->material;
}



Chair::Chair(int number, std::string factory, bool soft, bool adjustable):
Inventory (number, "����", factory), soft (soft), adjustable (adjustable) {

}

std::string Chair::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory + "', "
		+ (this->adjustable ? "������������" : "�� ������������") + ", " + (this->soft ? "� ������ ���������" : "� ������� ���������");
}


Monitor::Monitor(int number, std::string factory, int resWidth, int resHeight):
Inventory (number, "�������", factory), resolutionHeight (resHeight), resolutionWidth (resWidth) {

}

std::string Monitor::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory + "', "
		+ std::to_string(this->resolutionWidth) + "x" + std::to_string(this->resolutionHeight);
}

Computer::Computer(int number, std::string factory, std::string processor, bool integratedGPU):
Inventory (number, "���������", factory), processor (processor), integratedGPU (integratedGPU) {

}

std::string Computer::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory 
		+ "', ���������: " + this->processor + ", " + (this->integratedGPU ? "���������� ����������" : "���������� ����������");
}

Mouse::Mouse(int number, std::string factory, int dpiMin, int dpiMax):
Inventory(number, "������������ ����", factory), dpiMin (dpiMin), dpiMax (dpiMax) {

}

std::string Mouse::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory
		+ "', DPI �� " + std::to_string (this->dpiMin) + " �� " + std::to_string (this->dpiMax);
}
