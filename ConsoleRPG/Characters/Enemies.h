#pragma once
#include "../Common/commonInc.h"
#include "Enemy.h"

class Enemy;
class Enemies : public Serializer {
private:
	std::vector<std::shared_ptr<Enemy>> _enemyArray;
public:
	Enemies();
	~Enemies();
	
	Enemy* GetEnemyOnPlace(Point& place);
	void RemoveDefeated();
	
	void Serialize(tinyxml2::XMLElement& elem) override;
	void Serialize(tinyxml2::XMLElement& elem, tinyxml2::XMLDocument& doc);
	void Deserialize(tinyxml2::XMLElement& elem) override;
};