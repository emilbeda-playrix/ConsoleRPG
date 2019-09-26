#pragma once
#include "Console.h"
#include <fstream>

class Level {
private:
	int _levelIndex;
	int _levelHeight;
	string _fileName;
	string _levelLine[HEIGHT];
public:
	Level();
	virtual ~Level();

	void SetLevel(const int levelIndex);
	void LoadLevel();
	void RenderLevel() const;
};