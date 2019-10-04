#pragma once
#include "../Common/commonInc.h"
#include "../Inventory/Armor.h"
#include "../Inventory/Weapon.h"
#include "../Inventory/Potion.h"

constexpr int statsX = 90;
constexpr int statsY = 0;

class Player : public Drawable {
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
	void Render() override;
	void RenderPlayerStats() const;
	void MovePlayer(const int x, const int y);
	void EquipArmor(Armor* armor);
	void EquipWeapon(Weapon* weapon);
	void UsePotion(Potion* item);
	void EquipItem(Item* item);
	int GetAttackStrength() const { return _weapon->GetAttack(); }
	bool Attacked(int strength);
	void AddLevel() { ++_level; }
};