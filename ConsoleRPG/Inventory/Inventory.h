#pragma once
#include "../Common/commonInc.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

constexpr int inventoryX = 90;
constexpr int inventoryY = 10;


class Inventory : public Drawable
{
private:
	std::vector<std::shared_ptr<Item>> _itemArray;
	int _selectedIndex;
	int _usableItemCount;
	bool _selectEnabled;
	std::weak_ptr<Item> _selectedItem;
public:
	Inventory();
	~Inventory();
	void Init();
	void AddArmor(int x, int y, const char* name, int defence, int level);
	void AddWeapon(const int x, const int y, const char* name, const int attack, const int durability, const int level);
	void AddPotion(const int x, const int y, const char* name, const int potionType);
	void Render() override;
	void PickItemOnPlace(const int x, const int y);
	void CheckRemoveFlags();
	Armor* GetArmorByName(const char* name);
	Weapon* GetWeaponByName(const char* name);

	void ToggleSelect();
	void MoveCursor(const bool dir);

	bool GetSelectActive() const { return _selectEnabled; }
	std::weak_ptr<Item> GetSelectedItem() const { return _selectedItem; }
};

