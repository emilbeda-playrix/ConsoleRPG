#pragma once
#include "Console.h"
#include "commonInc.h"

class Player {
private:
	Position pos;
public:
	Player();
	virtual ~Player();
	void renderPlayer();
	void movePlayer(int x, int y);
	Position getPosition();
};