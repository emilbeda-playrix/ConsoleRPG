#include "Armor.h"

Armor::Armor(int x, int y, const char* name, int defence, int level) {
	_defence = defence;
	_level = level;
	AddItem(x, y, static_cast<int>(ItemTypes::Armor), name);
}

Armor::~Armor() {

}

void Armor::EquipArmor() {
	_picked = true;
	_equiped = true;
	RemoveDrawable();
}

void Armor::UnequipArmor() {
	_equiped = false;
	AddDrawable();
}