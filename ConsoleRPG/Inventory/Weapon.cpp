#include "Weapon.h"

Weapon::Weapon(const int x, const int y, const char* name, const int attack, const int durability, const int level) {
	_attack = attack;
	_maxDurability = durability;
	_durability = durability;
	_level = level;
	AddItem(x, y, static_cast<int>(ItemTypes::Weapon), name);
}

Weapon::~Weapon() {

}

void Weapon::EquipWeapon() {
	_picked = true;
	_equiped = true;
	RemoveDrawable();
}

void Weapon::UnequipWeapon() {
	_equiped = false;
	AddDrawable();
}
