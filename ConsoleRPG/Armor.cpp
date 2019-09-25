#include "Armor.h"

Armor::Armor(int x, int y, const char* name, int defence, int level) {
	this->defence = defence;
	this->level = level;
	this->addItem(x, y, ARMOR, name);
}

Armor::~Armor() {

}

void Armor::equipArmor() {
	this->Picked = true;
	this->Equiped = true;
}

void Armor::unequipArmor() {
	this->Equiped = false;
}