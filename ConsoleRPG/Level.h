#pragma once
#include "Console.h"
#include <fstream>

class Level {
private:
	int levelIndex;
	int levelHeight;
	string fileName;
	string levelLine[HEIGHT];
public:
	Level();
	virtual ~Level();

	void setLevel(int levelIndex);
	void loadLevel();
	void renderLevel();
};