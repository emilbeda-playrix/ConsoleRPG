#include "Enemies.h"

Enemies::Enemies() {

}

Enemies::~Enemies() {
	
}

void Enemies::AddEnemy(const int x, const int y, const int health, const int attack, const int defence) {
	_enemyArray.push_back(new Enemy(x, y, health, attack, defence));
}

void Enemies::RemoveDefeated()
{
	int place = 0;
	for (Enemy* enemy : _enemyArray)
	{
		if(enemy->GetDefeated())
		{
			_enemyArray.erase(_enemyArray.begin() + place);
		}
		++place;
	}
}


void Enemies::RenderEnemies() {
	for (Enemy* enemy : _enemyArray) {
		enemy->RenderEnemy();
	}
}

Enemy* Enemies::GetEnemyOnPlace(Point* place) {
	for (Enemy* enemy : _enemyArray) {
		if (enemy->GetPosition() == *place) {
			return enemy;
		}
	}
	return nullptr;
}