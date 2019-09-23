#include "item.h"

Item::Item() {
	cout << "created";
}

Item::Item(int x, int y, int type, int typeIndex) {
	this->Picked = false;
	this->Used = false;
	this->addItem(x, y, type, typeIndex);
}

Item::~Item() {
	cout << "destroyed";

}

void Item::addItem(int x, int y, int type, int typeIndex) {
	this->itemPos.X = x;
	this->itemPos.Y = y;
	this->Type = type;
	this->TypeIndex = typeIndex;
}

void Item::pickItem() {
	this->Picked = true;
}

void Item::renderItem() {

}

void Item::printItem() {
	if (!this->Picked) {
		Console::Get().moveCursor(this->itemPos.X, this->itemPos.Y);
		Console::Get().setColor(11);
		cout << (char)254;
	}
}