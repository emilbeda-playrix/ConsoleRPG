#pragma once
#include "Item.h"

class Weapon : public Item {
private:

public:
	Weapon(int x, int y, int typeIndex);
	virtual ~Weapon();
};