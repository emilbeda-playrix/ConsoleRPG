#include "Game.h"

Game::Game() {
	Console::Get().consoleInit();
	level.setLevel(1);
	level.loadLevel();
	player.movePlayer(11, 10);


	inventory.addItem(5, 5, ARMOR, 1);
	inventory.addItem(10, 5, WEAPON, 1);
	inventory.addItem(8, 8, POTION, 3);

	renderGame();
	gameLoop();
	cin.get();
}

Game::~Game() {

}

void Game::gameLoop() {
	this->keyPressed = tolower(_getch());
	Position currentPos;
	currentPos.X = player.getPosition().X;
	currentPos.Y = player.getPosition().Y;
	Position playerPos = player.getPosition();
	switch (this->keyPressed)
	{
	case 'w':
		currentPos.Y--;
		break;
	case 's':
		currentPos.Y++;
		break;
	case 'a':
		currentPos.X--;

		break;
	case 'd':
		currentPos.X++;

		break;
	default:
		break;
	}
	char placeChar = Console::Get().getChar(currentPos.X, currentPos.Y);
	switch (placeChar)
	{
	case 35:
		
		break;

	case (char)254:
		inventory.pickItemOnPlace(currentPos.X, currentPos.Y);
		player.movePlayer(currentPos.X, currentPos.Y);
		break;
	default:
		player.movePlayer(currentPos.X, currentPos.Y);
		break;
	}
	renderGame();
	gameLoop();
}

void Game::renderGame() {
	system("CLS");
	Console::Get().moveCursor(0, 0);
	Console::Get().setColor(15);
	level.renderLevel();
	player.renderPlayer();
	inventory.renderMapItems();
	inventory.renderInventory();
}