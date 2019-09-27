#include "Game.h"

Game::Game() {
	_keyPressed = '\0';
	_level.SetLevel(1);
	_level.LoadLevel();
	_player.MovePlayer(8, 3);

	_inventory.AddArmor(0, 0, "Leather Armor", 10, 1);
	_inventory.AddArmor(47, 7, "Warrior Armor", 20, 3);
	_inventory.AddArmor(8, 26, "Knight Armor", 30, 5);
	
	_inventory.AddWeapon(0, 0, "Dagger", 15, 10, 1);
	_inventory.AddWeapon(55, 1, "Claymore", 30, 30, 3);
	_inventory.AddWeapon(2, 16, "Zweihander", 50, 50, 5);

	_inventory.AddPotion(21, 2, "Health Potion", static_cast<int>(PotionTypes::Heal));
	
	_player.EquipArmor(_inventory.GetArmorByName("Leather Armor"));
	_player.EquipWeapon(_inventory.GetWeaponByName("Dagger"));

	_enemies.AddEnemy(6, 10, 50, 10, 5);
	_enemies.AddEnemy(25, 9, 70, 15, 7);
	_enemies.AddEnemy(27, 3, 50, 10, 5);
	_enemies.AddEnemy(62, 9, 50, 15, 5);
	_enemies.AddEnemy(73, 5, 70, 20, 10);
	
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
	Point currentPos = _player.GetPosition();
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
	const bool enemyDefeated = enemy->Attacked(_player.GetAttackStrength());
	if (!enemyDefeated)
	{
		const bool playerDefeated = _player.Attacked(enemy->GetAttackStrength());
	}
	else
	{
		_enemies.RemoveDefeated();
	}
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
			std::shared_ptr<Item> item(_inventory.GetSelectedItem());
			_player.EquipItem(item.get());
			_inventory.CheckRemoveFlags();
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