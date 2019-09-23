#pragma once
#include "commonInc.h"
#include "Item.h"
#include <vector>

class Inventory
{
private:
	std::vector<Item*> itemArray;
public:
	Inventory();
	~Inventory();
	void addItem(int x, int y, int type, int typeIndex);
	void renderMapItems();
	void renderInventory();
	void pickItemOnPlace(int x, int y);
};

