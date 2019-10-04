#pragma once
#include "../Common/commonInc.h"
#include "Enemy.h"

class Enemy;
class Enemies {
private:
	std::vector<std::shared_ptr<Enemy>> _enemyArray;
public:
	Enemies();
	~Enemies();
	void AddEnemy(const int x, const int y, const int health, const int attack, const int defence);
	Enemy* GetEnemyOnPlace(Point& place);
	void RemoveDefeated();
};