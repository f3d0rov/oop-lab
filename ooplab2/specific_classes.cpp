
#include "specific_classes.hpp"

Table::Table (int number, std::string factory, std::string material):
Inventory (number, "Стол", factory), material (material) {

}

std::string Table::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory + "', материал: " + this->material;
}



Chair::Chair(int number, std::string factory, bool soft, bool adjustable):
Inventory (number, "Стул", factory), soft (soft), adjustable (adjustable) {

}

std::string Chair::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory + "', "
		+ (this->adjustable ? "регулируемый" : "не регулируемый") + ", " + (this->soft ? "с мягким покрытием" : "с твердым покрытием");
}


Monitor::Monitor(int number, std::string factory, int resWidth, int resHeight):
Inventory (number, "Монитор", factory), resolutionHeight (resHeight), resolutionWidth (resWidth) {

}

std::string Monitor::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory + "', "
		+ std::to_string(this->resolutionWidth) + "x" + std::to_string(this->resolutionHeight);
}

Computer::Computer(int number, std::string factory, std::string processor, bool integratedGPU):
Inventory (number, "Компьютер", factory), processor (processor), integratedGPU (integratedGPU) {

}

std::string Computer::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory 
		+ "', процессор: " + this->processor + ", " + (this->integratedGPU ? "встроенная видеокарта" : "дискретная видеокарта");
}

Mouse::Mouse(int number, std::string factory, int dpiMin, int dpiMax):
Inventory(number, "Компьютерная мышь", factory), dpiMin (dpiMin), dpiMax (dpiMax) {

}

std::string Mouse::str() const {
	return std::string("[") + std::to_string(this->number) + "] " + this->type + " '" + this->factory
		+ "', DPI от " + std::to_string (this->dpiMin) + " до " + std::to_string (this->dpiMax);
}
