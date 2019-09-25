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
	std::vector<Item*> itemArray;
	int selectedIndex;
	int usableItemCount;
	bool selectEnabled;
	Item* selectedItem;
public:
	Inventory();
	~Inventory();
	void addItem(Item* item);
	void renderMapItems();
	void renderInventory();
	void pickItemOnPlace(int x, int y);
	Armor* getArmorByName(const char* name);
	Weapon* getWeaponByName(const char* name);

	void toggleSelect();
	void moveCursor(bool dir);

	bool getSelectActive() { return selectEnabled; }
	Item* getSelectedItem() { return selectedItem; }
};

