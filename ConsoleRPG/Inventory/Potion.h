#pragma once
#include "Item.h"
class Potion : public Item {
private:
	int _potionType;
public:
	Potion(const int x, const int y, const char* name, const int potionType);
	~Potion();
	int GetPotionType() const { return _potionType; }
};