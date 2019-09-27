#include "Inventory.h"

Inventory::Inventory()
{	
	_selectEnabled = false;
}

Inventory::~Inventory()
{
}

void Inventory::AddItem(const std::shared_ptr<Item> &item) {
	_itemArray.push_back(item);
}

void Inventory::AddArmor(int x, int y, const char* name, int defence, int level)
{
	_itemArray.push_back(std::make_shared<Armor>(x, y, name, defence, level));
}

void Inventory::AddWeapon(const int x, const int y, const char* name, const int attack, const int durability, const int level)
{
	_itemArray.push_back(std::make_shared<Weapon>(x, y, name, attack, durability, level));
}


void Inventory::AddPotion(const int x, const int y, const char* name, const int potionType)
{
	_itemArray.push_back(std::make_shared<Potion>(x, y, name, potionType));
}


void Inventory::CheckRemoveFlags()
{
	int place = 0;
	{
		for (const std::shared_ptr<Item> &item : _itemArray)
		{
			if (item->_removeFlag)
			{
				_itemArray.erase(_itemArray.begin() + place);
			}
			++place;
		}
	}
}


Armor* Inventory::GetArmorByName(const char* name) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->_type == ARMOR && item->GetName() == name) {
			auto* ret = dynamic_cast<Armor*>(item.get());
			return ret;
		}
	}
	return nullptr;
}

Weapon* Inventory::GetWeaponByName(const char* name) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->_type == WEAPON && item->GetName() == name) {
			auto* ret = dynamic_cast<Weapon*>(item.get());
			return ret;
		}
	}
	return nullptr;
}

void Inventory::RenderMapItems() {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		item->RenderItem();
	}
}

void Inventory::RenderInventory() {
	int cursorPos = inventoryY;
	int itemIndex = 1;
	Console::GetInstance().MoveCursor(inventoryX, cursorPos++);
	Console::GetInstance().SetColor(10);
	cout << "Inventory:";

	for (const std::shared_ptr<Item> &item : _itemArray) {
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
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (!item->_picked && item->_itemPos.x == x && item->_itemPos.y == y) {
			item->PickItem();
		}
	}
}

void Inventory::ToggleSelect() {
	if (!_selectEnabled) {
		_usableItemCount = 0;
		for (const std::shared_ptr<Item> &item : _itemArray) {
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
		_selectedItem = nullptr;
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