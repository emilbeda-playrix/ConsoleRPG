#include "Potion.h"

Potion::Potion(int x, int y, const char* name) {
	AddItem(x, y, POTION, name);
}

Potion::~Potion() {

}