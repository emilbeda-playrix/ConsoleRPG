#pragma once
#include "commonInc.h"

class Item
{
private:
	const char* Name;
public:
	int Type;
	bool Picked;
	bool Used;
	bool Equiped;
	Position itemPos;
	Item();
	Item(int x, int y, int type, const char* name);
	~Item();
	void addItem(int x, int y, int type, const char* name);
	void pickItem();
	void renderItem();
	const char* getName() { return Name; }
};