#include "Potion.h"

Potion::Potion(const int x, const int y, const char* name, const int potionType) {
	_potionType = potionType;
	AddItem(x, y, static_cast<int>(ItemTypes::Potion), name);
}

Potion::~Potion() {
}

void Potion::SerializeSpecific(TiXmlElement& elem)
{
	elem.SetAttribute("_potionType", _potionType);
}