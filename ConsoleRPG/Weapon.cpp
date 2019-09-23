#include "Weapon.h"

Weapon::Weapon(int x, int y, int typeIndex) {
	this->Picked = false;
	this->Used = false;
	this->addItem(x, y, WEAPON, typeIndex);
}

Weapon::~Weapon() {

}