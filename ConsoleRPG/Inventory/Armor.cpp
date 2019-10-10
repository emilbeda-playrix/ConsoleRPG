#include "Armor.h"

Armor::Armor()
{
	_defence = 0;
	_level = 0;
}

Armor::~Armor() {

}

void Armor::EquipArmor() {
	_picked = true;
	_equipped = true;
	RemoveDrawable();
}

void Armor::UnequipArmor() {
	_equipped = false;
	AddDrawable();
}

void Armor::SerializeSpecific(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("_defence", _defence);
	elem.SetAttribute("_level", _level);
}

void Armor::DeserializeSpecific(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("_defence", &_defence);
	elem.QueryIntAttribute("_level", &_level);
	Deserialize(elem);
	
}