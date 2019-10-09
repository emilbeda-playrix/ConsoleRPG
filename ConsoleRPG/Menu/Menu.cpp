#include "Menu.h"

Menu* Menu::_instance;

Menu::Menu()
{
	
}

Menu::~Menu()
{
	
}

void Menu::Init()
{
	_menuActive = true;
	_menuEvent = 0;
	_selectedIndex = 1;
	_menuList.emplace_back(std::make_shared<std::string>("-New Game-"));
	std::fstream saveFile;
	saveFile.open("Save.xml");
	if (saveFile)
	{
		_menuList.emplace_back(std::make_shared<std::string>("-Continue-"));
	}
	saveFile.close();
	_menuList.emplace_back(std::make_shared<std::string>("-Exit-"));
}


int Menu::MenuLoop()
{
	while (_menuActive)
	{
		Render();
		ProcessInput();
	}
	return _menuEvent;
}

void Menu::ProcessInput()
{
	const int keyPressed = Events::GetInstance().WaitKeyPress();
	switch (keyPressed)
	{
		case static_cast<int>(KeyPressed::KeyUp):
			if (_selectedIndex > 1) { --_selectedIndex; }
			break;
		case static_cast<int>(KeyPressed::KeyDown) :
			if (static_cast<int>(_menuList.size()) > _selectedIndex) { ++_selectedIndex; }
			break;
		case static_cast<int>(KeyPressed::KeyReturn) :
			if (_selectedIndex == 1) { _menuEvent = static_cast<int>(MenuEvent::NewGame); }
			if (static_cast<int>(_menuList.size()) == 3)
			{
				if (_selectedIndex == 2) { _menuEvent = static_cast<int>(MenuEvent::Continue); }
				if (_selectedIndex == 3) { _menuEvent = static_cast<int>(MenuEvent::Exit); }
			} else
			{
				if (_selectedIndex == 2) { _menuEvent = static_cast<int>(MenuEvent::Exit); }
			}
			_menuActive = false;
			break;
		default:
			break;
	}
}


void Menu::Render()
{
	system("CLS");
	int size = _menuList.size();
	int pointerY = MENU_Y;
	int index = 1;
	for (auto &item : _menuList)
	{
		if (_selectedIndex == index)
		{
			Console::GetInstance().Print(MENU_X, pointerY++, item->c_str(), 250);
		}
		else
		{
			Console::GetInstance().Print(MENU_X,pointerY++, item->c_str(),10);
		}
		++index;
	}
	Console::GetInstance().SetColor(10);
}
