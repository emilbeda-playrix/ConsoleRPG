#pragma once
#include "commonInc.h"
#include "Console.h"
#include "Armor.h"
#include "Weapon.h"

constexpr int statX = 90;
constexpr int statY = 0;

class Player {
private:
	Position pos;
	int health;
	int level;
	Armor* armor;
	Weapon* weapon;
public:
	Player();
	virtual ~Player();
	Position getPosition();
	void renderPlayer();
	void renderPlayerStats();
	void movePlayer(int x, int y);
	void equipArmor(Armor* armor);
	void equipWeapon(Weapon* weapon);
};