#pragma once
#include "item.h"
class Armor 
	: public Item {
private:
	int _defence;
	int _level;
public:
	Armor();
	virtual ~Armor();
	
	int GetDefence() const { return _defence; }
	int GetLevel() const { return _level; }
	
	void EquipArmor();
	void UnequipArmor();
	
	void SerializeSpecific(tinyxml2::XMLElement &elem);
	void DeserializeSpecific(tinyxml2::XMLElement& elem);
};