#include "Inventory.h"

Inventory::Inventory()
{	
	selectEnabled = false;
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Item* item) {
	this->itemArray.push_back(item);
}

Armor* Inventory::getArmorByName(const char* name) {
	for (Item* item : this->itemArray) {
		if (item->Type == ARMOR && item->getName() == name) {
			Armor* ret = (Armor*)item;
			return ret;
		}
	}
}

Weapon* Inventory::getWeaponByName(const char* name) {
	for (Item* item : this->itemArray) {
		if (item->Type == WEAPON && item->getName() == name) {
			Weapon* ret = (Weapon*)item;
			return ret;
		}
	}
}

void Inventory::renderMapItems() {
	for (Item* item : this->itemArray) {
		item->renderItem();
	}
}

void Inventory::renderInventory() {
	int cursorPos = inventoryY;
	int itemIndex = 1;
	Console::Get().moveCursor(inventoryX, cursorPos++);
	Console::Get().setColor(10);
	cout << "Inventory:";

	for (Item* item : this->itemArray) {
		if (item->Picked && !item->Equiped) {
			Console::Get().moveCursor(inventoryX, cursorPos++);
			if (this->selectEnabled && itemIndex == this->selectedIndex) {
				Console::Get().setColor(250);
				this->selectedItem = item;
			}
			else {
				Console::Get().setColor(10);
			}
			cout << itemIndex++ << ": " << item->getName();
		}
	}
	Console::Get().setColor(10);
}

void Inventory::pickItemOnPlace(int x, int y) {
	for (Item* item : this->itemArray) {
		if (!item->Picked && item->itemPos.X == x && item->itemPos.Y == y) {
			item->pickItem();
		}
	}
}

void Inventory::toggleSelect() {
	if (!this->selectEnabled) {
		this->usableItemCount = 0;
		for (Item* item : this->itemArray) {
			if (item->Picked && !item->Used && !item->Equiped) {
				this->usableItemCount++;
				if (this->usableItemCount == 1) { this->selectedItem = item; }
			}
		}
		if (this->usableItemCount > 0) {
			this->selectEnabled = true;
			this->selectedIndex = 1;
		}
	}
	else {
		this->selectEnabled = false;
	}
}

void Inventory::moveCursor(bool dir) {
	if (this->selectEnabled) {
		if (dir) {
			if (this->selectedIndex < this->usableItemCount) { this->selectedIndex++; }
		}
		else {
			if (this->selectedIndex > 1) { this->selectedIndex--; }
		}
	}
}