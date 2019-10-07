#pragma once
#include "item.h"
class Armor 
	: public Item {
private:
	int _defence;
	int _level;
public:
	Armor(int x, int y, const char* name, int defence, int level);
	virtual ~Armor();
	int GetDefence() const { return _defence; }
	int GetLevel() const { return _level; }
	void EquipArmor();
	void UnequipArmor();
	void SerializeSpecific(TiXmlElement &elem);
};