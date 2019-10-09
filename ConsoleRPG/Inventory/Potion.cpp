#include "Potion.h"

Potion::Potion()
{
	_potionType = 0;
}

Potion::Potion(const int x, const int y, const char* name, const int potionType) {
	_potionType = potionType;
	AddItem(x, y, static_cast<int>(ItemTypes::Potion), name);
}

Potion::~Potion() {
}

void Potion::SerializeSpecific(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("_potionType", _potionType);
}

void Potion::DeserializeSpecific(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("_potionType", &_potionType);
	Deserialize(elem);
}
