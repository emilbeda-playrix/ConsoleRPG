#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

Enemy::Enemy(int x, int y, int health, int attack, int defence) {
	this->position.X = x;
	this->position.Y = y;
	this->health = health;
	this->attack = attack;
	this->defence = defence;
}

void Enemy::renderEnemy() {
	Console::Get().moveCursor(this->position.X, this->position.Y);
	Console::Get().setColor(12);
	cout << (char)254;
}