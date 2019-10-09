#include "Weapon.h"

Weapon::Weapon()
{
	_attack = 0;
	_maxDurability = 0;
	_durability = 0;
	_level = 0;
}

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
	_equipped = true;
	RemoveDrawable();
}

void Weapon::UnequipWeapon() {
	_equipped = false;
	AddDrawable();
}

void Weapon::SerializeSpecific(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("_attack", _attack);
	elem.SetAttribute("_maxDurability", _maxDurability);
	elem.SetAttribute("_durability", _durability);
	elem.SetAttribute("_level", _level);
}

void Weapon::DeserializeSpecific(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("_attack", &_attack);
	elem.QueryIntAttribute("_maxDurability", &_maxDurability);
	elem.QueryIntAttribute("_durability", &_durability);
	elem.QueryIntAttribute("_level", &_level);
	Deserialize(elem);
}
