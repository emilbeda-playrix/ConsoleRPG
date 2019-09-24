#include "item.h"

Item::Item() {
	cout << "created";
}

Item::Item(int x, int y, int type, const char* name) {
	this->Picked = false;
	this->Used = false;
	this->addItem(x, y, type, name);
}

Item::~Item() {
	cout << "destroyed";

}

void Item::addItem(int x, int y, int type, const char* name) {
	this->itemPos.X = x;
	this->itemPos.Y = y;
	this->Picked = false;
	this->Used = false;
	this->Equiped = false;
	this->Type = type;
	this->Name = name;
}

void Item::pickItem() {
	this->Picked = true;
}

void Item::renderItem() {
	if (!this->Picked) {
		Console::Get().moveCursor(this->itemPos.X, this->itemPos.Y);
		Console::Get().setColor(14);
		cout << (char)233;
	}
}