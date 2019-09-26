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
	void AddEnemy(int x, int y, int health, int attack, int defence);
	void RenderEnemies();
	Enemy* GetEnemyOnPlace(Point* place);
};