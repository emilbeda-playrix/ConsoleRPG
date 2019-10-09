#include "Game.h"

Game* Game::_instance;

Game::Game() {
	_gameActive = true;
}

Game::~Game() {

}

void Game::Init()
{
	_map.Init();
	_inventory.Init();
	_player.Init();
	Log::GetInstance().Init();
}

bool Game::GameLoop() {
	const int keyPressed = Events::GetInstance().WaitKeyPress();
	_inventory.ProcessInput(keyPressed);
	if (!_inventory.GetSelectActive()) {
		if (keyPressed == static_cast<int>(KeyPressed::KeyEscape)) { return false; }
		_player.ProcessInput(keyPressed);
		if (_player.GetPosition() == _map.GetFinish()) { GameCompleted(); }
	}
	if (!_gameActive) { return false; }
	RenderGame();
	SaveGame();
	Log::GetInstance().Clear();
	return true;
}

void Game::Fight(Point& position) {
	Enemy* enemy = _enemies.GetEnemyOnPlace(position);
	const bool enemyDefeated = enemy->Attacked(_player.GetAttackStrength());
	if (!enemyDefeated)
	{
		_player.Attacked(enemy->GetAttackStrength());
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

void Game::GameOver()
{
	_gameActive = false;
	std::remove("Save.xml");
	system("CLS");
	Console::GetInstance().Print(55, 18, "-GAME OVER-", 10);
	Sleep(2000);
}

void Game::GameCompleted()
{
	_gameActive = false;
	std::remove("Save.xml");
	system("CLS");
	Console::GetInstance().Print(52, 18, "-CONGRATULATION-", 10);
	Console::GetInstance().Print(45, 19, "-YOU HAVE COMPLETED YOUR QUEST-", 10);
	Sleep(2000);
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
			_drawableItems.erase(_drawableItems.begin() + place);
			break;
		}
		++place;
	}
}

void Game::SaveGame()
{
	using namespace tinyxml2;
	
	tinyxml2::XMLDocument doc;
	
	XMLElement* root = doc.NewElement("Level");
	doc.LinkEndChild(root);

	XMLElement* map = doc.NewElement("Map");
	_map.Serialize(*map);
	root->LinkEndChild(map);

	XMLElement* inventory = doc.NewElement("Inventory");
	_inventory.Serialize(*inventory, doc);
	root->LinkEndChild(inventory);
	
	XMLElement* player = doc.NewElement("Player");
	_player.Serialize(*player);
	root->LinkEndChild(player);

	XMLElement* enemies = doc.NewElement("Enemies");
	_enemies.Serialize(*enemies, doc);
	root->LinkEndChild(enemies);
	
	doc.SaveFile("Save.xml");
}

void Game::LoadGame(const bool newGame)
{
	using namespace tinyxml2;
	tinyxml2::XMLDocument doc;
	if (newGame)
	{
		doc.LoadFile("Level_1.xml");
		std::remove("Save.xml");
	} else
	{
		doc.LoadFile("Save.xml");
	}

	XMLNode* root = doc.FirstChild();
	if(root != nullptr)
	{
		XMLElement* element = root->FirstChildElement("Map");
		if (element != nullptr)
		{
			_map.Deserialize(*element);
		}

		element = root->FirstChildElement("Inventory");
		if(element != nullptr)
		{
			XMLElement* listElement = element->FirstChildElement("Item");
			while (listElement != nullptr)
			{
				_inventory.Deserialize(*listElement);
				listElement = listElement->NextSiblingElement("Item");
			}
		}
		
		element = root->FirstChildElement("Player");
		if (element != nullptr)
		{
			_player.Deserialize(*element);
		}
		
		element = root->FirstChildElement("Enemies");
		if (element != nullptr)
		{
			XMLElement* listElement = element->FirstChildElement("Enemy");
			while (listElement != nullptr)
			{
				_enemies.Deserialize(*listElement);
				listElement = listElement->NextSiblingElement("Enemy");
			}
		}
	}
	RenderGame();
}
