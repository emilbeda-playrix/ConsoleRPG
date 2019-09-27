#pragma once
#include "commonInc.h"
#include <iostream>
#include <conio.h>
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemies.h"
#include "Inventory.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

using namespace std;

class Game {
private:
	char _keyPressed;
	Player _player;
	Level _level;
	Enemies _enemies;
	Inventory _inventory;
	std::vector<Enemy*> _enemyArray;
public:
	Game();
	virtual ~Game();
	void GameLoop();
	void RenderGame();
	void MovePlayer();
	void InventoryInput();
	void Fight(Enemy* enemy);
};