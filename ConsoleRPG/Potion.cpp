#include "Potion.h"

Potion::Potion(int x, int y, const char* name) {
	this->addItem(x, y, POTION, name);
}

Potion::~Potion() {

}