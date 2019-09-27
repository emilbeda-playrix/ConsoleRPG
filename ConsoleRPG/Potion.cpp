#include "Potion.h"

Potion::Potion(const int x, const int y, const char* name, const int potionType) {
	_potionType = potionType;
	AddItem(x, y, POTION, name);
}

Potion::~Potion() {
	cout << "destroyed";
}