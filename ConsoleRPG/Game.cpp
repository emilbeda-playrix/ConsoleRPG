#include "Game.h"

Game::Game() {
	_keyPressed = '\0';
}

Game::~Game() {

}

void Game::Init()
{
	_map.Init();
	_inventory.Init();
	_player.Init();
}


void Game::LoadElements()
{

	_map.SetMap(1);
	_map.LoadMap();
	_player.MovePlayer(8, 3);
	
	_inventory.AddArmor(0, 0, "Leather Armor", 10, 1);
	_inventory.AddArmor(47, 7, "Warrior Armor", 20, 4);
	_inventory.AddArmor(8, 26, "Knight Armor", 30, 8);
	_inventory.AddArmor(5, 24, "Havel Armor", 50, 12);
	
	_inventory.AddWeapon(0, 0, "Dagger", 15, 20, 1);
	_inventory.AddWeapon(55, 1, "Claymore", 30, 30, 4);
	_inventory.AddWeapon(2, 16, "Zweihander", 50, 50, 8);
	_inventory.AddWeapon(38, 21, "Artorias Greatsword", 60, 60, 12);

	_inventory.AddPotion(21, 2, "Health Potion", static_cast<int>(PotionTypes::Heal));
	_inventory.AddPotion(85, 9, "Health Potion", static_cast<int>(PotionTypes::Heal));
	_inventory.AddPotion(44, 15, "Health Potion", static_cast<int>(PotionTypes::Heal));
	_inventory.AddPotion(2, 27, "Health Potion", static_cast<int>(PotionTypes::Heal));
	_inventory.AddPotion(58, 23, "Health Potion", static_cast<int>(PotionTypes::Heal));
	_inventory.AddPotion(52, 11, "Repair Powder", static_cast<int>(PotionTypes::Repair));
	_inventory.AddPotion(55, 15, "Repair Powder", static_cast<int>(PotionTypes::Repair));
	_inventory.AddPotion(62, 12, "Repair Powder", static_cast<int>(PotionTypes::Repair));
	_inventory.AddPotion(14, 24, "Repair Powder", static_cast<int>(PotionTypes::Repair));
	_inventory.AddPotion(16, 31, "Repair Powder", static_cast<int>(PotionTypes::Repair));
	
	_player.EquipArmor(_inventory.GetArmorByName("Leather Armor"));
	_player.EquipWeapon(_inventory.GetWeaponByName("Dagger"));

	_enemies.AddEnemy(6, 10, 50, 10, 5);
	_enemies.AddEnemy(25, 9, 70, 15, 7);
	_enemies.AddEnemy(27, 3, 50, 10, 5);
	_enemies.AddEnemy(62, 9, 50, 15, 5);
	_enemies.AddEnemy(73, 5, 70, 20, 10);
	_enemies.AddEnemy(42, 4, 50, 10, 5);
	_enemies.AddEnemy(82, 13, 80, 25, 15);
	_enemies.AddEnemy(72, 20, 80, 30, 20);
	_enemies.AddEnemy(39, 19, 80, 30, 20);
	_enemies.AddEnemy(31, 22, 90, 30, 20);
	_enemies.AddEnemy(15, 17, 90, 30, 25);
	_enemies.AddEnemy(4, 30, 100, 40, 30);
	_enemies.AddEnemy(32, 29, 90, 35, 25);
	_enemies.AddEnemy(48, 23, 90, 30, 20);
	_enemies.AddEnemy(60, 30, 120, 40, 35);

	SaveGame();
	RenderGame();
}


void Game::GameLoop() {
	_keyPressed = tolower(_getch());
	InventoryInput();
	if (!_inventory.GetSelectActive()) {
		MovePlayer();
	}
	RenderGame();
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
	case static_cast<char>(Symbols::Item):
		_inventory.PickItemOnPlace(currentPos.x, currentPos.y);
		_player.MovePlayer(currentPos.x, currentPos.y);
		break;
	case static_cast<char>(Symbols::Enemy):
		Fight(_enemies.GetEnemyOnPlace(currentPos));
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
		const int rnd = rand() % 8;
		if (rnd <=1)
			_inventory.AddPotion(enemy->GetPosition().x, enemy->GetPosition().y, "Health Potion", static_cast<int>(PotionTypes::Heal));
		if (rnd == 2)
			_inventory.AddPotion(enemy->GetPosition().x, enemy->GetPosition().y, "Repair Powder", static_cast<int>(PotionTypes::Repair));
		
		_player.AddLevel();
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
			const std::shared_ptr<Item> item(_inventory.GetSelectedItem());
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

	int place = 0;
	for (auto &item : _drawableItems)
	{
		if (item )
		{
			item->Render();
		}
		place++;
	}
}

void Game::AddDrawable(Drawable* item)
{
	_drawableItems.push_back(item);
}


void Game::RemoveDrawable()
{
	int place = 0;
	for ( auto &item : _drawableItems)
	{
		if (item && item->GetRemoveDrawable())
		{
			break;
		}
		++place;
	}
	_drawableItems.erase(_drawableItems.begin() + place);
}

void Game::SaveGame()
{
	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);
	
	TiXmlElement * root = new TiXmlElement("Level");
	doc.LinkEndChild(root);
	
	TiXmlElement* map = new TiXmlElement("Map");
	map->SetAttribute("_mapIndex", 1);
	root->LinkEndChild(map);

	TiXmlElement* player = new TiXmlElement("Player");
	_player.Serialize(*player);
	root->LinkEndChild(player);

	TiXmlElement* inventory = new TiXmlElement("Inventory");
	_inventory.Serialize(*inventory);
	root->LinkEndChild(inventory);

	TiXmlElement* enemies = new TiXmlElement("Enemies");
	_enemies.Serialize(*enemies);
	root->LinkEndChild(enemies);
	
	doc.SaveFile("Save.xml");
}
