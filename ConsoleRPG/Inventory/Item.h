#pragma once
#include "../Common/commonInc.h"

class Item : public Drawable, public Serializer
{
protected:
	const char* _name;
	int _type;
	bool _picked;
	bool _used;
	bool _equiped;
	bool _removeFlag;
	Point _itemPos;
public:
	Item();
	Item(const int x, const int y, const int type, const char* name);
	virtual ~Item();
	void AddItem(const int x, const int y, const int type, const char* name);
	void PickItem();
	const char* GetName() const { return _name; }
	int GetType() const { return _type; }
	bool GetPicked() const { return _picked; }
	bool GetUsed() const { return _used; }
	bool GetEquiped() const { return _equiped; }
	bool GetRemoveFlag() const { return _removeFlag; }
	Point GetPosition() const { return _itemPos; }
	void SetRemoveFlag() { _removeFlag = true; }

	void AddDrawable();
	void RemoveDrawable();
	void Render() override;
	void Serialize(TiXmlElement &elem) override;
};