#pragma once
#include "commonInc.h"

class Enemy {
private:
	Point _position;
	int _health;
	int _attack;
	int _defence;
public:
	Enemy();
	Enemy(const int x, const int y, const int health, const int attack, const int defence);
	~Enemy();

	void RenderEnemy() const;
	Point GetPosition() const { return _position; }
};