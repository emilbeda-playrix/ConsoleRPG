#include "Potion.h"

Potion::Potion(int x, int y, int typeIndex) {
	this->Picked = false;
	this->Used = false;
	this->addItem(x, y, POTION, typeIndex);
}

Potion::~Potion() {

}