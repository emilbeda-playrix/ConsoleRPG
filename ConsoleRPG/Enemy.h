#pragma once
#include "commonInc.h"

class Enemy {
private:
	Position position;
	int health;
	int attack;
	int defence;
public:
	Enemy();
	Enemy(int x, int y, int health, int attack, int defence);
	~Enemy();

	void renderEnemy();
	Position getPosition() { return position; }
};