#pragma once
#include "../Common/commonInc.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

constexpr int INVENTORY_X = 90;
constexpr int INVENTORY_Y = 10;


class Inventory : public Drawable, public Serializer
{
private:
	std::vector<std::shared_ptr<Item>> _itemArray;
	int _selectedIndex;
	int _usableItemCount;
	bool _selectEnabled;
	std::shared_ptr<Item> _selectedItem;
public:
	static Inventory& GetInstance() {
		static Inventory instance;
		return instance;
	}
	Inventory();
	~Inventory();
	void Init();
	void AddPotion(const int x, const int y, const char* name, const int potionType);
	void Render() override;
	void PickItemOnPlace(const int x, const int y);
	void CheckRemoveFlags();
	Armor* GetArmorByName(const char* name); 
	Weapon* GetWeaponByName(const char* name);

	void ProcessInput(const int keyPressed);
	void ToggleSelect();

	bool GetSelectActive() const { return _selectEnabled; }
	std::weak_ptr<Item> GetSelectedItem() const { return _selectedItem; }
	
	void Serialize(tinyxml2::XMLElement& elem ) override;
	void Serialize(tinyxml2::XMLElement &elem, tinyxml2::XMLDocument &doc);
	void Deserialize(tinyxml2::XMLElement& elem) override;
};

