#include "Inventory.h"
#include "../Game.h"

Inventory::Inventory()
{	
	_selectEnabled = false;
}

Inventory::~Inventory()
{
}

void Inventory::Init()
{
	Game::GetInstance().AddDrawable(this);
}

void Inventory::AddArmor(int x, int y, const char* name, int defence, int level)
{
	_itemArray.emplace_back(std::make_shared<Armor>(x, y, name, defence, level));
}

void Inventory::AddWeapon(const int x, const int y, const char* name, const int attack, const int durability, const int level)
{
	_itemArray.emplace_back(std::make_shared<Weapon>(x, y, name, attack, durability, level));
}


void Inventory::AddPotion(const int x, const int y, const char* name, const int potionType)
{
	_itemArray.emplace_back(std::make_shared<Potion>(x, y, name, potionType));
}


void Inventory::CheckRemoveFlags()
{
	int place = 0;
	for (const std::shared_ptr<Item> &item : _itemArray)
	{
		if (item && item->GetRemoveFlag())
		{
			break;
		}
		++place;
	}
	_itemArray.erase(_itemArray.begin() + place);
}


Armor* Inventory::GetArmorByName(const char* name) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->GetType() == static_cast<int>(ItemTypes::Armor) && item->GetName() == name) {
			auto* ret = dynamic_cast<Armor*>(item.get());
			return ret;
		}
	}
	return nullptr;
}

Weapon* Inventory::GetWeaponByName(const char* name) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->GetType() == static_cast<int>(ItemTypes::Weapon) && item->GetName() == name) {
			auto* ret = dynamic_cast<Weapon*>(item.get());
			return ret;
		}
	}
	return nullptr;
}

void Inventory::Render() {
	int cursorPos = inventoryY;
	int itemIndex = 1;

	Console::GetInstance().Print(inventoryX, inventoryY, "Inventory:", 10);

	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->GetPicked() && !item->GetEquiped()) {
			if (_selectEnabled && itemIndex == _selectedIndex) {
				Console::GetInstance().Print(inventoryX, ++cursorPos, std::to_string((itemIndex++)) + ": " + item->GetName(), 250);
				_selectedItem = item;
			}
			else {
				Console::GetInstance().Print(inventoryX, ++cursorPos, std::to_string((itemIndex++)) + ": " + item->GetName(), 10);
			}
		}
	}
	Console::GetInstance().SetColor(10);
}

void Inventory::PickItemOnPlace(const int x, const int y) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (!item->GetPicked() && item->GetPosition().x == x && item->GetPosition().y == y) {
			item->PickItem();
		}
	}
}

void Inventory::ToggleSelect() {
	if (!_selectEnabled) {
		_usableItemCount = 0;
		for (const std::shared_ptr<Item> &item : _itemArray) {
			if (item->GetPicked() && !item->GetUsed() && !item->GetEquiped()) {
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

void Inventory::MoveCursor(const bool dir) {
	if (_selectEnabled) {
		if (dir) {
			if (_selectedIndex < _usableItemCount) { _selectedIndex++; }
		}
		else {
			if (_selectedIndex > 1) { _selectedIndex--; }
		}
	}
}