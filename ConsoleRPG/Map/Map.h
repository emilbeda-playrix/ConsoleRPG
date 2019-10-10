#pragma once
#include "../Common/commonInc.h"
#include <fstream>

class Map : public Drawable, public Serializer {
private:
	Point _finish;
	int _mapIndex;
	int _mapHeight;
	std::string _fileName;
	std::string _mapLine[HEIGHT];
public:
	Map();
	~Map();
	
	Point GetFinish() const { return _finish; }
	
	void Init();
	void LoadMap();

	void Render() override;
	
	void Serialize(tinyxml2::XMLElement& elem) override;
	void Deserialize(tinyxml2::XMLElement& elem) override;

	
};