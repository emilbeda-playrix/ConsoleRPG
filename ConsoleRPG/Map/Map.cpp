#include "Map.h"
#include  "../Game.h"

Map::Map() {
	_mapHeight = 0;
	_mapIndex = 1;
}

Map::~Map() {
	
}

void Map::Init()
{
	Game::GetInstance()->AddDrawable(this);
}

void Map::LoadMap() {
	_fileName = "Level_" + std::to_string(_mapIndex) + ".txt";
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

void Map::Serialize(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("_mapIndex", _mapIndex);
	elem.SetAttribute("_finishX", _finish.x);
	elem.SetAttribute("_finishY", _finish.y);
}


void Map::Deserialize(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("_mapIndex", &_mapIndex);
	elem.QueryIntAttribute("_finishX", &_finish.x);
	elem.QueryIntAttribute("_finishY", &_finish.y);
	LoadMap();
}
