#pragma once
#include "commonInc.h"
#include "Console.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

constexpr int statsX = 90;
constexpr int statsY = 0;

class Player {
private:
	Point _position;
	int _maxHealth;
	int _health;
	int _level;
	Armor* _armor;
	Weapon* _weapon;
public:
	Player();
	virtual ~Player();
	Point GetPosition() const { return _position; }
	void RenderPlayer() const;
	void RenderPlayerStats();
	void MovePlayer(int x, int y);
	void EquipArmor(Armor* armor);
	void EquipWeapon(Weapon* weapon);
	void UsePotion(Potion* item);
	void EquipItem(Item* item);
	int GetAttackStrength() const { return _weapon->GetAttack(); }
	bool Attacked(int strength);
};