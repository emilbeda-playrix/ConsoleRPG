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
	Enemy(const int x, const int y, const int health, const int attack, const int defence);
	~Enemy();

	void Render() override;
	Point GetPosition() const { return _position; }
	bool Attacked(int strength);
	int GetAttackStrength() const { return _attack; }
	bool GetDefeated() const { return _defeated; }
	void Serialize(tinyxml2::XMLElement& elem) override;
	void Deserialize(tinyxml2::XMLElement& elem) override;
};