#include "Game.h"

Game::Game() {
	_keyPressed = '\0';
	_level.SetLevel(1);
	_level.LoadLevel();
	_player.MovePlayer(8, 3);

	_inventory.AddItem(new Armor(0, 0, "Leather Armor", 10, 1));
	_inventory.AddItem(new Armor(47, 7, "Warrior Armor", 20, 3));
	_inventory.AddItem(new Armor(8, 26, "Knight Armor", 30, 5));
	_inventory.AddItem(new Weapon(0, 0, "Dagger", 5, 10, 1));
	_inventory.AddItem(new Weapon(55, 1, "Claymore", 2, 30, 3));
	_inventory.AddItem(new Weapon(2, 16, "Zweihander", 30, 50, 5));

	_player.EquipArmor(_inventory.GetArmorByName("Leather Armor"));
	_player.EquipWeapon(_inventory.GetWeaponByName("Dagger"));

	_enemies.AddEnemy(6, 10, 50, 5, 5);
	_enemies.AddEnemy(25, 9, 70, 7, 7);
	_enemies.AddEnemy(27, 3, 50, 5, 5);
	_enemies.AddEnemy(62, 9, 50, 7, 5);
	_enemies.AddEnemy(73, 5, 70, 10, 10);
	
	RenderGame();
	GameLoop();
	cin.get();
}

Game::~Game() {

}

void Game::GameLoop() {
	_keyPressed = tolower(_getch());
	InventoryInput();
	if (!_inventory.GetSelectActive()) {
		MovePlayer();
	}
	RenderGame();
	GameLoop();
}

void Game::MovePlayer() {
	Point currentPos;
	currentPos.x = _player.GetPosition().x;
	currentPos.y = _player.GetPosition().y;
	Point playerPos = _player.GetPosition();
	switch (_keyPressed)
	{
	case 'w':
		currentPos.y--;
		break;
	case 's':
		currentPos.y++;
		break;
	case 'a':
		currentPos.x--;
		break;
	case 'd':
		currentPos.x++;
		break;
	default:
		break;
	}

	const char placeChar = Console::GetInstance().GetChar(currentPos.x, currentPos.y);
	switch (placeChar)
	{
	case 35:
		break;
	case static_cast<char>(233):
		_inventory.PickItemOnPlace(currentPos.x, currentPos.y);
		_player.MovePlayer(currentPos.x, currentPos.y);
		break;
	case static_cast<char>(254):
		Fight(_enemies.GetEnemyOnPlace(&currentPos));
		break;
	default:
		_player.MovePlayer(currentPos.x, currentPos.y);
		break;
	}
}

void Game::Fight(Enemy* enemy) {

}

void Game::InventoryInput() {
	switch (_keyPressed)
	{
	case 'w':
		_inventory.MoveCursor(false);
		break;
	case 's':
		_inventory.MoveCursor(true);
		break;
	case 'i':
		_inventory.ToggleSelect();
		break;
	case static_cast<char>(13): {
		if (_inventory.GetSelectActive()) {
			Item* item = _inventory.GetSelectedItem();
			_player.EquipItem(item);
			_inventory.ToggleSelect();
		}
	}
	default:
		break;
	}
}

void Game::RenderGame() {
	system("CLS");
	_level.RenderLevel();
	_player.RenderPlayer();
	_player.RenderPlayerStats();
	_enemies.RenderEnemies();
	_inventory.RenderMapItems();
	_inventory.RenderInventory();
}