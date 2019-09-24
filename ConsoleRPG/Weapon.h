#pragma once
#include "Item.h"

class Weapon : public Item {
private:
	int attack;
	int durability;
	int level;
public:
	Weapon(int x, int y, const char* name, int attack, int durability, int level);
	virtual ~Weapon();
	void equipWeapon();
	int getAttack() { return attack; }
	int getDurability() { return durability; }
	int getLevel() { return level; }
};