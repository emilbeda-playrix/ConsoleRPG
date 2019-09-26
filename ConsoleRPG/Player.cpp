#include "Player.h"

Player::Player() {
	_level = 1;
	_health = 100;
}

Player::~Player() {
	
}

void Player::MovePlayer(int x, int y) {
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

void Player::EquipItem(Item* item) {
	switch (item->_type) 
	{
	case WEAPON:
		EquipWeapon(dynamic_cast<Weapon*>(item));
		break;
	case ARMOR:
		EquipArmor(dynamic_cast<Armor*>(item));
		break;
	case POTION:
		break;
	default:
		break;
	}
}

void Player::RenderPlayer() const {
	Console::GetInstance().MoveCursor(_position.x,_position.y);
	Console::GetInstance().SetColor(14);
	cout << "@";
}

void Player::RenderPlayerStats() {
	Console::GetInstance().SetColor(14);
	int line = statsY;
	Console::GetInstance().MoveCursor(statsX, line++);
	cout << "Health: " << _health;
	Console::GetInstance().MoveCursor(statsX, line++);
	cout << "Level: " << _level;
	Console::GetInstance().MoveCursor(statsX, line++);
	if (_armor) {
		cout << "Armor: " << _armor->GetName();
		Console::GetInstance().MoveCursor(statsX, line++);
		cout << "Defence: " << _armor->GetDefence();
		Console::GetInstance().MoveCursor(statsX, line++);
	}
	if (_weapon) {
		cout << "Weapon: " << _weapon->GetName();
		Console::GetInstance().MoveCursor(statsX, line++);
		cout << "Attack: " << _weapon->GetAttack();
		Console::GetInstance().MoveCursor(statsX, line++);
		cout << "Durability: " << _weapon->GetDurability();
	}
}
