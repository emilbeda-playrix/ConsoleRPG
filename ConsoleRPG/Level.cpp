#include "Level.h"
#include "commonInc.h"

Level::Level() {

}

void Level::setLevel(int levelIndex) {
	this->levelHeight = 0;
	this->levelIndex = levelIndex;
	this->fileName = "Level_" + to_string(levelIndex) + ".txt";
}

Level::~Level() {

}

void Level::loadLevel() {
	int index = 0;
	ifstream openFile(this->fileName.c_str());
	if (openFile.is_open()) {
		while (!openFile.eof()) {
			getline(openFile, this->levelLine[index]);
			this->levelHeight = index;
			index++;
		}
	}
}

void Level::renderLevel() {
	Console::Get().moveCursor(0, 0);
	Console::Get().setColor(15);
	for (int i = 0; i <= this->levelHeight; i++) {
		cout << this->levelLine[i] << "\n";
	}
}