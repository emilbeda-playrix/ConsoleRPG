#pragma once
#include "Item.h"

class Weapon : public Item {
private:
	int _attack;
	int _durability;
	int _maxDurability;
	int _level;
public:
	Weapon(const int x, const int y, const char* name, const int attack, const int durability, const int level);
	virtual ~Weapon();
	void EquipWeapon();
	void UnequipWeapon();
	int GetAttack() const { return _attack; }
	int GetDurability() const { return _durability; }
	int GetLevel() const { return _level; }
	void ResetDurability() { _durability = _maxDurability; }
};