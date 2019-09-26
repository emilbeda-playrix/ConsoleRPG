#include "Enemies.h"

Enemies::Enemies() {

}

Enemies::~Enemies() {

}

void Enemies::AddEnemy(int x, int y, int health, int attack, int defence) {
	_enemyArray.push_back(new Enemy(x, y, health, attack, defence));
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