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
	std::vector<std::shared_ptr<Item>> _itemArray;
	int _selectedIndex;
	int _usableItemCount;
	bool _selectEnabled;
	std::shared_ptr<Item> _selectedItem;
	//Item* _selectedItem;
public:
	Inventory();
	virtual ~Inventory();
	void AddItem(const std::shared_ptr<Item> &item);
	void AddArmor(int x, int y, const char* name, int defence, int level);
	void AddWeapon(const int x, const int y, const char* name, const int attack, const int durability, const int level);
	void AddPotion(const int x, const int y, const char* name, const int potionType);
	void RenderMapItems();
	void RenderInventory();
	void PickItemOnPlace(int x, int y);
	void CheckRemoveFlags();
	Armor* GetArmorByName(const char* name);
	Weapon* GetWeaponByName(const char* name);

	void ToggleSelect();
	void MoveCursor(bool dir);

	bool GetSelectActive() const { return _selectEnabled; }
	std::weak_ptr<Item> GetSelectedItem() const { return _selectedItem; }
};

