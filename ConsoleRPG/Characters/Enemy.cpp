#include "Enemy.h"
#include "../Game.h"

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
	Game::GetInstance().AddDrawable(this);
}

void Enemy::Render() {
	Console::GetInstance().Print(_position.x, _position.y, std::string(1, static_cast<char>(Symbols::Enemy)), 12);
}

bool Enemy::Attacked(int strength)
{
	strength -= (_defence < strength) ? _defence : strength - 1;
	_health -= (strength <= _health) ? strength : _health;
	if (_health == 0)
	{
		_defeated = true;
		_removeDrawable = true;
		Game::GetInstance().RemoveDrawable();
		return true;
	}
	return false;
}

void Enemy::Serialize(TiXmlElement& elem)
{
	elem.SetAttribute("x", _position.x);
	elem.SetAttribute("y", _position.y);
	elem.SetAttribute("_health", _health);
	elem.SetAttribute("_attack", _attack);
	elem.SetAttribute("_defence", _defence);
	elem.SetAttribute("_defeated", _defeated);
}
