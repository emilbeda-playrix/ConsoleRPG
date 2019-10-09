#include "Item.h"
#include "../Game.h"

Item::Item() {
	_removeFlag = false;
	_itemPos.x = 0;
	_itemPos.y = 0;
	_picked = false;
	_used = false;
	_equipped = false;
	_type = 0;
	_name = "";
}

Item::Item(const int x, const int y, const int type, const char* name) {
	_removeFlag = false;
	_picked = false;
	_used = false;
	AddItem(x, y, type, name);
}

Item::~Item() {
}

void Item::AddItem(const int x, const int y, const int type, const char* name) {
	_removeFlag = false;
	_itemPos.x = x;
	_itemPos.y = y;
	_picked = false;
	_used = false;
	_equipped = false;
	_type = type;
	_name = name;

	AddDrawable();
	
}

void Item::PickItem() {
	_picked = true;
	RemoveDrawable();
}

void Item::AddDrawable()
{
	Game::GetInstance()->AddDrawable(this);
}

void Item::RemoveDrawable()
{
	_removeDrawable = true;
	Game::GetInstance()->RemoveDrawable();
}

void Item::Render()
{
	Console::GetInstance().Print(_itemPos.x, _itemPos.y, std::string(1, static_cast<char>(Symbols::Item)), 9);
}

void Item::Serialize(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("x", _itemPos.x);
	elem.SetAttribute("y", _itemPos.y);
	elem.SetAttribute("_name", _name.c_str());
	elem.SetAttribute("_type", _type);
	elem.SetAttribute("_picked", _picked);
	elem.SetAttribute("_used", _used);
	elem.SetAttribute("_equipped", _equipped);
	
	switch (_type)
	{
	case static_cast<int>(ItemTypes::Weapon) :
		(dynamic_cast<Weapon*>(this))->SerializeSpecific(elem);
		break;
	case static_cast<int>(ItemTypes::Armor) :
		(dynamic_cast<Armor*>(this))->SerializeSpecific(elem);
		break;
	case static_cast<int>(ItemTypes::Potion) :
		(dynamic_cast<Potion*>(this))->SerializeSpecific(elem);	
		break;
	}
	
}

void Item::Deserialize(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("x", &_itemPos.x);
	elem.QueryIntAttribute("y", &_itemPos.y);
	_name = elem.Attribute("_name");
	//elem.QueryStringAttribute("_name", &_name);
	elem.QueryIntAttribute("_type", &_type);
	elem.QueryBoolAttribute("_picked", &_picked);
	elem.QueryBoolAttribute("_used", &_used);
	elem.QueryBoolAttribute("_equipped", &_equipped);
	if (!_picked)
	{
		AddDrawable();
	}
}