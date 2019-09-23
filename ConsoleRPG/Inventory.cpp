#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::addItem(int x, int y, int type, int typeIndex) {
	switch (type)
	{
	case WEAPON:
		this->itemArray.push_back(new Weapon(x, y, typeIndex));
		break;
	case ARMOR:
		this->itemArray.push_back(new Armor(x, y, typeIndex));
		break;
	case POTION:
		this->itemArray.push_back(new Potion(x, y, typeIndex));
		break;
	default:
		break;
	}
}

void Inventory::renderMapItems() {
	for (Item* item : this->itemArray) {
		item->printItem();
	}
}

void Inventory::renderInventory() {
	int cursorPos = 0;
	int itemIndex = 1;
	Console::Get().moveCursor(90, cursorPos++);
	Console::Get().setColor(10);
	cout << "Inventory:";

	for (Item* item : this->itemArray) {
		if (item->Picked && !item->Used) {
			Console::Get().moveCursor(90, cursorPos++);
			cout << itemIndex++ << ": " << item->Name;
		}
	}
}

void Inventory::pickItemOnPlace(int x, int y) {
	for (Item* item : this->itemArray) {
		if (!item->Picked && item->itemPos.X == x && item->itemPos.Y == y) {
			item->pickItem();
		}
	}
}