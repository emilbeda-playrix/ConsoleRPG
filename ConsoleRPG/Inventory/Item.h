#pragma once
#include "../Common/commonInc.h"

class Item : public Drawable, public Serializer
{
protected:
	std::string _name;
	int _type;
	bool _picked;
	bool _used;
	bool _equipped;
	bool _removeFlag;
	Point _itemPos;
public:
	Item();
	virtual ~Item();
	
	void AddItem(const int x, const int y, const int type, const char* name);
	void PickItem();
	
	const char* GetName() const { return _name.c_str(); }
	int GetType() const { return _type; }
	bool GetPicked() const { return _picked; }
	bool GetUsed() const { return _used; }
	bool GetEquipped() const { return _equipped; }
	bool GetRemoveFlag() const { return _removeFlag; }
	Point GetPosition() const { return _itemPos; }
	void SetRemoveFlag() { _removeFlag = true; }

	void AddDrawable();
	void RemoveDrawable();
	
	void Render() override;
	
	void Serialize(tinyxml2::XMLElement &elem) override;
	void Deserialize(tinyxml2::XMLElement& elem) override;
};