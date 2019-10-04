#pragma once
#include "../Common/commonInc.h"
#include <fstream>

class Map : public Drawable {
private:
	int _mapIndex;
	int _mapHeight;
	std::string _fileName;
	std::string _mapLine[HEIGHT];
public:
	Map();
	~Map();

	void Init();
	void SetMap(const int mapIndex);
	void LoadMap();
	void Render() override;
};