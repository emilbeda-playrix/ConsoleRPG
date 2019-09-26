#include "Inventory.h"

Inventory::Inventory()
{	
	_selectEnabled = false;
}

Inventory::~Inventory()
{
}

void Inventory::AddItem(Item* item) {
	_itemArray.push_back(item);
}

Armor* Inventory::GetArmorByName(const char* name) {
	for (Item* item : _itemArray) {
		if (item->_type == ARMOR && item->GetName() == name) {
			auto* ret = dynamic_cast<Armor*>(item);
			return ret;
		}
	}
}

Weapon* Inventory::GetWeaponByName(const char* name) {
	for (Item* item : _itemArray) {
		if (item->_type == WEAPON && item->GetName() == name) {
			auto* ret = dynamic_cast<Weapon*>(item);
			return ret;
		}
	}
}

void Inventory::RenderMapItems() {
	for (Item* item : _itemArray) {
		item->RenderItem();
	}
}

void Inventory::RenderInventory() {
	int cursorPos = inventoryY;
	int itemIndex = 1;
	Console::GetInstance().MoveCursor(inventoryX, cursorPos++);
	Console::GetInstance().SetColor(10);
	cout << "Inventory:";

	for (Item* item : _itemArray) {
		if (item->_picked && !item->_equiped) {
			Console::GetInstance().MoveCursor(inventoryX, cursorPos++);
			if (_selectEnabled && itemIndex == _selectedIndex) {
				Console::GetInstance().SetColor(250);
				_selectedItem = item;
			}
			else {
				Console::GetInstance().SetColor(10);
			}
			cout << itemIndex++ << ": " << item->GetName();
		}
	}
	Console::GetInstance().SetColor(10);
}

void Inventory::PickItemOnPlace(int x, int y) {
	for (Item* item : _itemArray) {
		if (!item->_picked && item->_itemPos.x == x && item->_itemPos.y == y) {
			item->PickItem();
		}
	}
}

void Inventory::ToggleSelect() {
	if (!_selectEnabled) {
		_usableItemCount = 0;
		for (Item* item : _itemArray) {
			if (item->_picked && !item->_used && !item->_equiped) {
				_usableItemCount++;
				if (_usableItemCount == 1) { _selectedItem = item; }
			}
		}
		if (_usableItemCount > 0) {
			_selectEnabled = true;
			_selectedIndex = 1;
		}
	}
	else {
		_selectEnabled = false;
	}
}

void Inventory::MoveCursor(bool dir) {
	if (_selectEnabled) {
		if (dir) {
			if (_selectedIndex < _usableItemCount) { _selectedIndex++; }
		}
		else {
			if (_selectedIndex > 1) { _selectedIndex--; }
		}
	}
}