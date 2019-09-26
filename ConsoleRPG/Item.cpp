#include "item.h"

Item::Item() {
	cout << "created";
}

Item::Item(const int x, const int y, const int type, const char* name) {
	_picked = false;
	_used = false;
	AddItem(x, y, type, name);
}

Item::~Item() {
	cout << "destroyed";

}

void Item::AddItem(const int x, const int y, const int type, const char* name) {
	_itemPos.x = x;
	_itemPos.y = y;
	_picked = false;
	_used = false;
	_equiped = false;
	_type = type;
	_name = name;
}

void Item::PickItem() {
	_picked = true;
}

void Item::RenderItem() const {
	if (!_picked) {
		Console::GetInstance().MoveCursor(_itemPos.x, _itemPos.y);
		Console::GetInstance().SetColor(14);
		cout << static_cast<char>(233);
	}
}