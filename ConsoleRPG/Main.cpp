#include "Game.h"

int main() {
	bool gameActive = true;
	Game::GetInstance().Init();
	Game::GetInstance().LoadElements();
	while (gameActive)
	{
		Game::GetInstance().GameLoop();
	}
	
}