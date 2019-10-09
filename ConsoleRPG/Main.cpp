#include "Menu/Menu.h"
#include "Game.h"

int main() {
	
	//Menu* menu = Menu::GetInstance();
	bool menuActive = true;
	while (menuActive)
	{
		Menu::GetInstance()->Init();
		const int menuEvent = Menu::GetInstance()->MenuLoop();
		if (menuEvent != static_cast<int>(MenuEvent::Exit))
		{
			Menu::DeleteInstance();
			Game::GetInstance()->Init();
			if (menuEvent == static_cast<int>(MenuEvent::NewGame))
			{
				Game::GetInstance()->LoadGame(true);
			} else
			{
				Game::GetInstance()->LoadGame(false);
			}
			bool gameActive = true;
			while (gameActive)
			{
				gameActive = Game::GetInstance()->GameLoop();
			}
			Game::DeleteInstance();
		} else
		{
			menuActive = false;
		}
	}
}