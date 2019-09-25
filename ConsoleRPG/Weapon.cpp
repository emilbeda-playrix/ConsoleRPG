#include "Weapon.h"

Weapon::Weapon(int x, int y, const char* name, int attack, int durability, int level) {
	this->attack = attack;
	this->durability = durability;
	this->level = level;
	this->addItem(x, y, WEAPON, name);
}

Weapon::~Weapon() {

}

void Weapon::equipWeapon() {
	this->Picked = true;
	this->Equiped = true;
}

void Weapon::unequipWeapon() {
	this->Equiped = false;
}