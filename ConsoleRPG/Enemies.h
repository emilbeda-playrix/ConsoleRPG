#pragma once
#include "commonInc.h"
#include "Enemy.h"
#include <vector>

class Enemies {
private:
	vector<Enemy*> _enemyArray;
public:
	Enemies();
	~Enemies();
	void AddEnemy(const int x, const int y, const int health, const int attack, const int defence);
	void RenderEnemies();
	Enemy* GetEnemyOnPlace(Point* place);
	void RemoveDefeated();
};