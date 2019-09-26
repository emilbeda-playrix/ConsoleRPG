#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

Enemy::Enemy(const int x, const int y, const int health, const int attack, const int defence) {
	_position.x = x;
	_position.y = y;
	_health = health;
	_attack = attack;
	_defence = defence;
}

void Enemy::RenderEnemy() const {
	Console::GetInstance().MoveCursor(_position.x, _position.y);
	Console::GetInstance().SetColor(12);
	cout << static_cast<char>(254);
}