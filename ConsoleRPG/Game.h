#pragma once
#include "commonInc.h"
#include <iostream>
#include <conio.h>
#include "Level.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

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