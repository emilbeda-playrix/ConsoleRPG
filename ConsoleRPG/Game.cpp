#include "Game.h"

Game::Game() {
	Console::Get().consoleInit();
	level.setLevel(1);
	level.loadLevel();
	player.movePlayer(11, 10);

	inventory.addItem(new Armor(0, 0, "Leather Armor", 10, 1));
	inventory.addItem(new Armor(47, 7, "Warrior Armor", 20, 3));
	inventory.addItem(new Armor(8, 26, "Knight Armor", 30, 5));
	inventory.addItem(new Weapon(0, 0, "Dagger", 5, 10, 1));
	inventory.addItem(new Weapon(55, 1, "Claymore", 2, 30, 3));
	inventory.addItem(new Weapon(2, 16, "Zweihander", 30, 50, 5));

	player.equipArmor(inventory.getArmorByName("Leather Armor"));
	player.equipWeapon(inventory.getWeaponByName("Dagger"));

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

	case (char)233:
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
	level.renderLevel();
	player.renderPlayer();
	player.renderPlayerStats();
	inventory.renderMapItems();
	inventory.renderInventory();
}