#include "Level.h"
#include "commonInc.h"

Level::Level() {

}

void Level::SetLevel(const int levelIndex) {
	_levelHeight = 0;
	_levelIndex = levelIndex;
	_fileName = "Level_" + to_string(_levelIndex) + ".txt";
}

Level::~Level() {

}

void Level::LoadLevel() {
	int index = 0;
	ifstream openFile(_fileName.c_str());
	if (openFile.is_open()) {
		while (!openFile.eof()) {
			getline(openFile, _levelLine[index]);
			_levelHeight = index;
			index++;
		}
	}
}

void Level::RenderLevel() const {
	Console::GetInstance().MoveCursor(0, 0);
	Console::GetInstance().SetColor(15);
	for (int i = 0; i <= _levelHeight; i++) {
		cout << _levelLine[i] << "\n";
	}
}