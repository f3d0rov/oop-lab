#pragma once

#include <iostream>

class Parent {
public:
	int publicVal = 0;
protected:
	int protectedVal = 1;
private:
	int privateVal = 2;
};

class PublicChild : public Parent {
public:
	PublicChild() {
		std::cout << publicVal;
		std::cout << protectedVal;
		//std::cout << privateVal;
	}
};

class ProtectedChild : protected Parent {
public:
	ProtectedChild() {
		std::cout << publicVal;
		std::cout << protectedVal;
		//std::cout << privateVal;
	}
};

class PrivateChild : private Parent {
public:
	PrivateChild() {
		std::cout << publicVal;
		std::cout << protectedVal;
		//std::cout << privateVal;
	}
};

/*
void testIncapsulation() {
        PublicChild pubC;
        ProtectedChild protC;
        PrivateChild privC;
        std::cout << std::endl;
}
*/
