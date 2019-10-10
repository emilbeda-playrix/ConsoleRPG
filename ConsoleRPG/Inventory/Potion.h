#pragma once
#include "Item.h"
class Potion : public Item {
private:
	int _potionType;
public:
	Potion();
	Potion(const int x, const int y, const char* name, const int potionType);
	~Potion();
	
	int GetPotionType() const { return _potionType; }
	
	void SerializeSpecific(tinyxml2::XMLElement &elem) const;
	void DeserializeSpecific(tinyxml2::XMLElement& elem);
};