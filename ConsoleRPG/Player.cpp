#include "Player.h"

Player::Player() {
	this->level = 1;
	this->health = 100;
}

Player::~Player() {
	
}

void Player::movePlayer(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void Player::equipArmor(Armor* armor) {
	if (this->level >= armor->getLevel()) {
		if (this->armor) {
			this->armor->unequipArmor();
		}
		this->armor = armor;
		armor->equipArmor();
	}
	else {
		//log
	}
}

void Player::equipWeapon(Weapon* weapon) {
	if (this->level >= weapon->getLevel()) {
		if (this->weapon) {
			this->weapon->unequipWeapon();
		}
		this->weapon = weapon;
		weapon->equipWeapon();
	}
	else {
		//log
	}
}

void Player::equipItem(Item* item) {
	switch (item->Type) 
	{
	case WEAPON:
		this->equipWeapon((Weapon*)item);
		break;
	case ARMOR:
		this->equipArmor((Armor*)item);
		break;
	case POTION:
		break;
	default:
		break;
	}
}

void Player::renderPlayer() {
	Console::Get().moveCursor(this->pos.X,this->pos.Y);
	Console::Get().setColor(14);
	cout << "@";
}

void Player::renderPlayerStats() {
	Console::Get().setColor(14);
	int line = statY;
	Console::Get().moveCursor(statX, line++);
	cout << "Health: " << this->health;
	Console::Get().moveCursor(statX, line++);
	cout << "Level: " << this->level;
	Console::Get().moveCursor(statX, line++);
	if (this->armor) {
		cout << "Armor: " << this->armor->getName();
		Console::Get().moveCursor(statX, line++);
		cout << "Defence: " << this->armor->getDefence();
		Console::Get().moveCursor(statX, line++);
	}
	if (this->weapon) {
		cout << "Weapon: " << this->weapon->getName();
		Console::Get().moveCursor(statX, line++);
		cout << "Attack: " << this->weapon->getAttack();
		Console::Get().moveCursor(statX, line++);
		cout << "Durability: " << this->weapon->getDurability();
	}
}

Position Player::getPosition() {
	return pos;
}
