#include "Player.h"
#include "../Game.h"

Player::Player() {
	_level = 1;
	_maxHealth = 100;
	_health = _maxHealth;
}

Player::~Player() {
	
}

void Player::Init()
{
	Game::GetInstance().AddDrawable(this);
}

void Player::MovePlayer(const int x, const int y) {
	_position.x = x;
	_position.y = y;
}

void Player::EquipArmor(Armor* armor) {
	if (_level >= armor->GetLevel()) {
		if (_armor) {
			_armor->UnequipArmor();
		}
		_armor = armor;
		armor->EquipArmor();
	}
	else {
		//log
	}
}

void Player::EquipWeapon(Weapon* weapon) {
	if (_level >= weapon->GetLevel()) {
		if (_weapon) {
			_weapon->UnequipWeapon();
		}
		_weapon = weapon;
		weapon->EquipWeapon();
	}
	else {
		//log
	}
}

void Player::UsePotion(Potion* item)
{
	switch (item->GetPotionType())
	{
	case static_cast<int>(PotionTypes::Heal) :
		_health = _maxHealth;
		break;
	case static_cast<int>(PotionTypes::Repair) :
		_weapon->ResetDurability();
		break;
	default:
		break;
	}
	item->SetRemoveFlag();
}


void Player::EquipItem(Item* item) {
	switch (item->GetType())
	{
	case static_cast<int>(ItemTypes::Weapon):
		EquipWeapon(dynamic_cast<Weapon*>(item));
		break;
	case static_cast<int>(ItemTypes::Armor):
		EquipArmor(dynamic_cast<Armor*>(item));
		break;
		case static_cast<int>(ItemTypes::Potion):
		UsePotion(dynamic_cast<Potion*>(item));
		break;
	default:
		break;
	}
}

bool Player::Attacked(int strength)
{
	_weapon->SubDurability();
	strength -= (_armor->GetDefence() < strength) ? _armor->GetDefence() : strength - 1;
	_health -= (strength <= _health) ? strength : _health;
	if (_health == 0)
	{
		return true;
	}
	return false;
}


void Player::Render() {
	Console::GetInstance().Print(_position.x, _position.y, std::string(1, static_cast<char>(Symbols::Player)), 14);

	//stats
	int line = statsY;
	
	Console::GetInstance().Print(statsX, line++, "Health: " + std::to_string(_health), 14);
	Console::GetInstance().Print(statsX, line++, "Level: " + std::to_string(_level), 14);
	if (_armor) {
		Console::GetInstance().Print(statsX, line++, "Armor: " + std::string(_armor->GetName()), 14);
		Console::GetInstance().Print(statsX, line++, "Defence: " + std::to_string(_armor->GetDefence()), 14);
	}
	if (_weapon) {
		Console::GetInstance().Print(statsX, line++, "Weapon: " + std::string(_weapon->GetName()), 14);
		Console::GetInstance().Print(statsX, line++, "Attack: " + std::to_string(_weapon->GetAttack()), 14);
		Console::GetInstance().Print(statsX,line++, "Durability: " + std::to_string(_weapon->GetDurability()),14);
	}
}

void Player::RenderPlayerStats() const {
}
