#pragma once
#include "item.h"
class Armor 
	: public Item {
private:
	int defence;
	int level;
public:
	Armor(int x, int y, const char* name, int defence, int level);
	virtual ~Armor();
	int getDefence() { return defence; }
	int getLevel() { return level; }
	void equipArmor();
	void unequipArmor();
};