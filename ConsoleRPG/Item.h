#pragma once
#include "commonInc.h"
class Item{
private:
	int TypeIndex;
public:
	string Name;
	int Type;
	bool Picked;
	bool Used;
	Position itemPos;
	Item();
	Item(int x, int y, int type, int typeIndex);
	~Item();
	void addItem(int x, int y, int type, int typeIndex);
	void pickItem();
	void renderItem();
	void printItem();
};