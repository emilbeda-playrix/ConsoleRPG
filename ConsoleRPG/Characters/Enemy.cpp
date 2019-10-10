#include "Enemy.h"
#include "../Game.h"

Enemy::Enemy() {
	_position.x = 0;
	_position.y = 0;
	_health = 0;
	_attack = 0;
	_defence = 0;
	_defeated = false;
}

Enemy::~Enemy() {

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
		Log::GetInstance().Add("Enemy Defeated");
		_defeated = true;
		_removeDrawable = true;
		Game::GetInstance()->RemoveDrawable();
		return true;
	} else
	{
		Log::GetInstance().Add("Enemy Attacked. Health: " + std::to_string(_health));
	}
	return false;
}

void Enemy::Serialize(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("x", _position.x);
	elem.SetAttribute("y", _position.y);
	elem.SetAttribute("_health", _health);
	elem.SetAttribute("_attack", _attack);
	elem.SetAttribute("_defence", _defence);
}

void Enemy::Deserialize(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("x", &_position.x);
	elem.QueryIntAttribute("y", &_position.y);
	elem.QueryIntAttribute("_health", &_health);
	elem.QueryIntAttribute("_attack", &_attack);
	elem.QueryIntAttribute("_defence", &_defence);
	Game::GetInstance()->AddDrawable(this);
}
