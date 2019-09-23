#pragma once
#include <iostream>
#include <conio.h>
#include "Console.h"
#include "Level.h"
#include "Player.h"
#include "Inventory.h"
#include "commonInc.h"
#include "Item.h"

using namespace std;

class Game {
private:
	bool gameActive;
	char keyPressed;
	Player player;
	Level level;
	Inventory inventory;
public:
	Game();
	virtual ~Game();
	void gameLoop();
	void renderGame();
};