#pragma once
#include <fstream>
#include "../Window/Console.h"
#include  "../Events/Events.h"

static constexpr int MENU_X = 55;
static constexpr int MENU_Y = 18;

enum class MenuEvent {NewGame = 0, Continue = 1, Exit = 2};

class Menu
{
private:
	static Menu* _instance;
	bool _menuActive;
	int _selectedIndex;
	int _menuEvent;
	std::vector<std::shared_ptr<std::string>> _menuList;
public:
	static Menu* GetInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new Menu();
		}
		return _instance;
	}
	static void DeleteInstance()
	{
		delete _instance;
		_instance = nullptr;
	}

	Menu();
	~Menu();
	void Init();
	int MenuLoop();
	void ProcessInput();
	void Render();
};

