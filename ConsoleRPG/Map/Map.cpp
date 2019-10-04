#include "Map.h"
#include  "../Game.h"

Map::Map() {
	
}

void Map::SetMap(const int mapIndex) {
	_mapHeight = 0;
	_mapIndex = mapIndex;
	_fileName = "Level_" + std::to_string(_mapIndex) + ".txt";
}

Map::~Map() {
	delete[] _mapLine;
}

void Map::Init()
{
	Game::GetInstance().AddDrawable(this);
}

void Map::LoadMap() {
	int index = 0;
	std::ifstream openFile(_fileName.c_str());
	if (openFile.is_open()) {
		while (!openFile.eof()) {
			getline(openFile, _mapLine[index]);
			_mapHeight = index;
			index++;
		}
	}
}

void Map::Render() {
	Console::GetInstance().MoveCursor(0, 0);
	Console::GetInstance().SetColor(15);
	for (int i = 0; i <= _mapHeight; i++) {
		Console::GetInstance().Print(0, i, _mapLine[i], 15);
	}
}