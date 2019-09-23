#include "Armor.h"

Armor::Armor(int x, int y, int typeIndex) {
	this->Picked = false;
	this->Used = false;
	this->addItem(x, y, ARMOR, typeIndex);
}

Armor::~Armor() {

}