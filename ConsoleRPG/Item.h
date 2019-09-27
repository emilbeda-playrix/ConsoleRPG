#pragma once
#include "commonInc.h"

class Item
{
private:
	const char* _name;
public:
	int _type;
	bool _picked;
	bool _used;
	bool _equiped;
	bool _removeFlag;
	Point _itemPos;
	Item();
	Item(const int x, const int y, const int type, const char* name);
	virtual ~Item();
	void AddItem(const int x, const int y, const int type, const char* name);
	void PickItem();
	void RenderItem() const;
	const char* GetName() const { return _name; }
	void SetRemoveFlag() { _removeFlag = true; }
};