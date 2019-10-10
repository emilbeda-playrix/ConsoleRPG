#include "Weapon.h"

Weapon::Weapon()
{
	_attack = 0;
	_maxDurability = 0;
	_durability = 0;
	_level = 0;
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

void Weapon::SerializeSpecific(tinyxml2::XMLElement& elem) const
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
