#include "Player.h"

Player::Player() {

}

Player::~Player() {
	
}

void Player::movePlayer(int x, int y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void Player::renderPlayer() {
	Console::Get().moveCursor(this->pos.X,this->pos.Y);
	Console::Get().setColor(14);
	cout << "@";
}

Position Player::getPosition() {
	return pos;
}