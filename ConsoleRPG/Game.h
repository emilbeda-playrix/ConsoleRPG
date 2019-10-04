#pragma once

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Common/commonInc.h"
#include "Map/Map.h"
#include "Characters/Player.h"
#include "Characters/Enemies.h"
#include "Inventory/Inventory.h"


class Enemy;
class Game {
private:
	char _keyPressed;
	Player _player;
	Map _map;

	Inventory _inventory;


	Enemies _enemies;
	
public:
	Game(Game const&) = delete;
	void operator = (Game const&) = delete;
	
	std::vector<Drawable*> _drawableItems;
	static Game& GetInstance() {
		static Game instance;
		return instance;
	}
	Game();
	virtual ~Game();

	void Init();
	void LoadElements();
	void GameLoop();
	void RenderGame();
	void MovePlayer();
	void InventoryInput();
	void Fight(Enemy* enemy);

	void AddDrawable(Drawable* item);
	void RemoveDrawable();
	
};