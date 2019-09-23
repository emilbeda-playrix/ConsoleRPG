#pragma once
#include "Item.h"
class Potion : public Item {
private:

public:
	Potion(int x, int y, int typeIndex);
	virtual ~Potion();
};