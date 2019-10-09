#pragma once

#include <iostream>
#include <conio.h>
#include "Common/commonInc.h"
#include "Map/Map.h"
#include "Characters/Player.h"
#include "Characters/Enemies.h"
#include "Inventory/Inventory.h"
#include "Events/Events.h"
#include "Window/Log.h"


class Enemy;
class Game {
private:
	static Game* _instance;
	Player _player;
	Map _map;
	Inventory _inventory;
	Enemies _enemies;
	friend class Player;
	friend  class Inventory;
	bool _gameActive;
public:
	std::vector<Drawable*> _drawableItems;
	static Game* GetInstance() {
		if (_instance == nullptr)
		{
			_instance = new Game();
		}
		return _instance;
	}
	static void DeleteInstance()
	{
		delete _instance;
		_instance = nullptr;
	}
	Game();
	~Game();

	void Init();
	
	bool GameLoop();
	
	void Fight(Point& position);
	void GameOver();
	void GameCompleted();

	void AddDrawable(Drawable* item);
	void RemoveDrawable();
	void RenderGame();
	
	void SaveGame();
	void LoadGame(const bool newGame);
};