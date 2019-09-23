#pragma once
#include "item.h"
class Armor 
	: public Item {
private:
	int typeIndex;
	int defence;

public:
	Armor(int x, int y, int typeIndex);
	virtual ~Armor();
};