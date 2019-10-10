#pragma once
#include "../Common/commonInc.h"
#include "../Inventory/Armor.h"
#include "../Inventory/Weapon.h"
#include "../Inventory/Potion.h"

constexpr int STATS_X = 90;
constexpr int STATS_Y = 0;

class Player : public Drawable, public Serializer {
private:
	Point _position;
	int _maxHealth;
	int _health;
	int _level;
	Armor* _armor;
	Weapon* _weapon;
public:
	Player();
	~Player();
	Point GetPosition() const { return _position; }
	
	void Init();

	void ProcessInput(const int keyPressed);
	
	void EquipItem(Item* item);
	void EquipArmor(Armor* armor);
	void EquipWeapon(Weapon* weapon);
	void UsePotion(Potion* item);
	
	void Attacked(int strength);
	void AddLevel() { ++_level; }
	
	int GetAttackStrength() const { return _weapon->GetAttack(); }
	
	void Render() override;
	
	void Serialize(tinyxml2::XMLElement &elem) override;
	void Deserialize(tinyxml2::XMLElement& elem) override;
};