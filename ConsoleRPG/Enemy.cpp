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
	_defeated = false;
}

void Enemy::RenderEnemy() const {
	if (!_defeated)
	{
		Console::GetInstance().MoveCursor(_position.x, _position.y);
		Console::GetInstance().SetColor(12);
		cout << static_cast<char>(254);
	}
}

bool Enemy::Attacked(int strength)
{
	strength -= (_defence < strength) ? _defence : strength - 1;
	_health -= (strength <= _health) ? strength : _health;
	if (_health == 0)
	{
		_defeated = true;
		return true;
	}
	return false;
}