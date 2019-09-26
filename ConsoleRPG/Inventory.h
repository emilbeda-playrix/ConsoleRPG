#pragma once
#include "commonInc.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
#include <vector>

constexpr int inventoryX = 90;
constexpr int inventoryY = 10;


class Inventory
{
private:
	std::vector<Item*> _itemArray;
	int _selectedIndex;
	int _usableItemCount;
	bool _selectEnabled;
	Item* _selectedItem;
public:
	Inventory();
	virtual ~Inventory();
	void AddItem(Item* item);
	void RenderMapItems();
	void RenderInventory();
	void PickItemOnPlace(int x, int y);
	Armor* GetArmorByName(const char* name);
	Weapon* GetWeaponByName(const char* name);

	void ToggleSelect();
	void MoveCursor(bool dir);

	bool GetSelectActive() const { return _selectEnabled; }
	Item* GetSelectedItem() const { return _selectedItem; }
};

