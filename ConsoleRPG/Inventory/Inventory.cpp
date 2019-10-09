#include "Inventory.h"
#include "../Game.h"

Inventory::Inventory()
{	
	_selectEnabled = false;
	_selectedIndex = 0;
	_usableItemCount = 0;
	_selectedItem = nullptr;
}

Inventory::~Inventory()
{
}

void Inventory::Init()
{
	Game::GetInstance()->AddDrawable(this);
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
			_itemArray.erase(_itemArray.begin() + place);
			break;
		}
		++place;
	}
}


Armor* Inventory::GetArmorByName(const char* name) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->GetType() == static_cast<int>(ItemTypes::Armor) && !strcmp(item->GetName(), name)) {
			auto* ret = dynamic_cast<Armor*>(item.get());
			return ret;
		}
	}
	return nullptr;
}

Weapon* Inventory::GetWeaponByName(const char* name) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->GetType() == static_cast<int>(ItemTypes::Weapon) && !strcmp(item->GetName(), name)) {
			auto* ret = dynamic_cast<Weapon*>(item.get());
			return ret;
		}
	}
	return nullptr;
}

void Inventory::Render() {
	int cursorPos = INVENTORY_Y;
	int itemIndex = 1;

	Console::GetInstance().Print(INVENTORY_X, INVENTORY_Y, "Inventory:", 10);

	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (item->GetPicked() && !item->GetEquipped()) {
			if (_selectEnabled && itemIndex == _selectedIndex) {
				Console::GetInstance().Print(INVENTORY_X, ++cursorPos, std::to_string((itemIndex++)) + ": " + item->GetName(), 250);
				_selectedItem = item;
			}
			else {
				Console::GetInstance().Print(INVENTORY_X, ++cursorPos, std::to_string((itemIndex++)) + ": " + item->GetName(), 10);
			}
		}
	}
	Console::GetInstance().SetColor(10);
}

void Inventory::PickItemOnPlace(const int x, const int y) {
	for (const std::shared_ptr<Item> &item : _itemArray) {
		if (!item->GetPicked() && item->GetPosition().x == x && item->GetPosition().y == y) {
			item->PickItem();
			Log::GetInstance().Add("Item Picked: " + static_cast<std::string>(item->GetName()));
		}
	}
}

void Inventory::ProcessInput(const int keyPressed)
{
	switch (keyPressed)
	{
		case static_cast<int>(KeyPressed::KeyUp):
			MoveCursor(false);
			break;
		case static_cast<int>(KeyPressed::KeyDown):
			MoveCursor(true);
			break;
		case static_cast<int>(KeyPressed::KeyInventory):
			ToggleSelect();
			break;
		case static_cast<int>(KeyPressed::KeyReturn) : 
			if (_selectEnabled) {
				Game::GetInstance()->_player.EquipItem(_selectedItem.get());
				CheckRemoveFlags();
				ToggleSelect();
			}
			break;
		case static_cast<int>(KeyPressed::KeyEscape):
			if(_selectEnabled)
			{
				ToggleSelect();
			}
			break;
		default:
			break;
	}
}


void Inventory::ToggleSelect() {
	if (!_selectEnabled) {
		_usableItemCount = 0;
		for (const std::shared_ptr<Item> &item : _itemArray) {
			if (item->GetPicked() && !item->GetUsed() && !item->GetEquipped()) {
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

void Inventory::Serialize(tinyxml2::XMLElement& elem)
{

}

void Inventory::Serialize(tinyxml2::XMLElement& elem, tinyxml2::XMLDocument& doc)
{
	for (std::shared_ptr<Item> &item : _itemArray)
	{
		if(item)
		{
			tinyxml2::XMLElement* el = doc.NewElement("Item");
			item->Serialize(*el);
			elem.LinkEndChild(el);
		}
	}
}

void Inventory::Deserialize(tinyxml2::XMLElement& elem)
{
	int type;
	elem.QueryIntAttribute("_type", &type);
	
	switch (type)
	{
	case static_cast<int>(ItemTypes::Armor) :
		_itemArray.emplace_back(std::make_shared<Armor>());
		(dynamic_cast<Armor*>(_itemArray.back().get()))->DeserializeSpecific(elem);
		break;
	case static_cast<int>(ItemTypes::Weapon):
		_itemArray.emplace_back(std::make_shared<Weapon>());
		(dynamic_cast<Weapon*>(_itemArray.back().get()))->DeserializeSpecific(elem);
		break;
	case static_cast<int>(ItemTypes::Potion):
		_itemArray.emplace_back(std::make_shared<Potion>());
		(dynamic_cast<Potion*>(_itemArray.back().get()))->DeserializeSpecific(elem);
		break;
	default:
		break;
	}
}
