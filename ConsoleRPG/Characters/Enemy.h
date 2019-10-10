#pragma once
#include "../Common/commonInc.h"

class Enemy : public Drawable, public Serializer {
private:
	Point _position;
	int _health;
	int _attack;
	int _defence;
	bool _defeated;
public:
	Enemy();
	~Enemy();

	bool Attacked(int strength);
	
	Point GetPosition() const { return _position; }
	int GetAttackStrength() const { return _attack; }
	bool GetDefeated() const { return _defeated; }

	void Render() override;
	
	void Serialize(tinyxml2::XMLElement& elem) override;
	void Deserialize(tinyxml2::XMLElement& elem) override;
};