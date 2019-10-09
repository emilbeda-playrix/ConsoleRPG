#include "Player.h"
#include "../Game.h"

Player::Player() {
	_level = 1;
	_maxHealth = 100;
	_health = _maxHealth;
	_position.x = 0;
	_position.y = 0;
	_armor = nullptr;
	_weapon = nullptr;
}

Player::~Player() {
	
}

void Player::Init()
{
	Game::GetInstance()->AddDrawable(this);
}

void Player::ProcessInput(const int keyPressed)
{
	Point nextPos = _position;
	switch (keyPressed)
	{
		case static_cast<int>(KeyPressed::KeyUp):
			nextPos.y--;
			break;
		case static_cast<int>(KeyPressed::KeyDown) :
			nextPos.y++;
			break;
		case static_cast<int>(KeyPressed::KeyLeft) :
			nextPos.x--;
			break;
		case static_cast<int>(KeyPressed::KeyRight) :
			nextPos.x++;
			break;
		default:
			break;
	}
	const char placeChar = Console::GetInstance().GetChar(nextPos.x, nextPos.y);
	switch (placeChar)
	{
		case static_cast<char>(Symbols::Wall):
			break;
		case static_cast<char>(Symbols::Item) :
			Game::GetInstance()->_inventory.PickItemOnPlace(nextPos.x, nextPos.y);
			_position = nextPos;
			break;
		case static_cast<char>(Symbols::Enemy) :
			Game::GetInstance()->Fight(nextPos);
			break;
		default:
			_position = nextPos;
			break;
	}
}

void Player::EquipArmor(Armor* armor) {
	if (_level >= armor->GetLevel()) {
		if (_armor) {
			_armor->UnequipArmor();
		}
		_armor = armor;
		armor->EquipArmor();
	}
	else {
		Log::GetInstance().Add("Cannot Equip. Required level: " + std::to_string(armor->GetLevel()));
	}
}

void Player::EquipWeapon(Weapon* weapon) {
	if (_level >= weapon->GetLevel()) {
		if (_weapon) {
			_weapon->UnequipWeapon();
		}
		_weapon = weapon;
		weapon->EquipWeapon();
	}
	else {
		Log::GetInstance().Add("Cannot Equip. Required level: " + std::to_string(weapon->GetLevel()));
	}
}

void Player::UsePotion(Potion* item)
{
	switch (item->GetPotionType())
	{
	case static_cast<int>(PotionTypes::Heal) :
		_health = _maxHealth;
		break;
	case static_cast<int>(PotionTypes::Repair) :
		_weapon->ResetDurability();
		break;
	default:
		break;
	}
	item->SetRemoveFlag();
}


void Player::EquipItem(Item* item) {
	switch (item->GetType())
	{
	case static_cast<int>(ItemTypes::Weapon):
		EquipWeapon(dynamic_cast<Weapon*>(item));
		break;
	case static_cast<int>(ItemTypes::Armor):
		EquipArmor(dynamic_cast<Armor*>(item));
		break;
		case static_cast<int>(ItemTypes::Potion):
		UsePotion(dynamic_cast<Potion*>(item));
		break;
	default:
		break;
	}
}

void Player::Attacked(int strength)
{
	_weapon->SubDurability();
	strength -= (_armor->GetDefence() < strength) ? _armor->GetDefence() : strength - 1;
	_health -= (strength <= _health) ? strength : _health;
	if (_health == 0)
	{
		Game::GetInstance()->GameOver();
	}
}


void Player::Render() {
	Console::GetInstance().Print(_position.x, _position.y, std::string(1, static_cast<char>(Symbols::Player)), 14);

	//stats
	int line = STATS_Y;
	
	Console::GetInstance().Print(STATS_X, line++, "Health: " + std::to_string(_health), 14);
	Console::GetInstance().Print(STATS_X, line++, "Level: " + std::to_string(_level), 14);
	if (_armor) {
		Console::GetInstance().Print(STATS_X, line++, "Armor: " + std::string(_armor->GetName()), 14);
		Console::GetInstance().Print(STATS_X, line++, "Defence: " + std::to_string(_armor->GetDefence()), 14);
	}
	if (_weapon) {
		Console::GetInstance().Print(STATS_X, line++, "Weapon: " + std::string(_weapon->GetName()), 14);
		Console::GetInstance().Print(STATS_X, line++, "Attack: " + std::to_string(_weapon->GetAttack()), 14);
		Console::GetInstance().Print(STATS_X,line++, "Durability: " + std::to_string(_weapon->GetDurability()),14);
	}
}

void Player::Serialize(tinyxml2::XMLElement& elem)
{
	elem.SetAttribute("x", GetPosition().x);
	elem.SetAttribute("y", GetPosition().y);
	elem.SetAttribute("_health", _health);
	elem.SetAttribute("_level", _level);
	elem.SetAttribute("_armor", _armor ? _armor->GetName(): "");
	elem.SetAttribute("_weapon",  _weapon ? _weapon->GetName(): "");
}

void Player::Deserialize(tinyxml2::XMLElement& elem)
{
	elem.QueryIntAttribute("x", &_position.x);
	elem.QueryIntAttribute("y", &_position.y);
	elem.QueryIntAttribute("_health", &_health);
	elem.QueryIntAttribute("_level", &_level);
	EquipArmor(Game::GetInstance()->_inventory.GetArmorByName(elem.Attribute("_armor")));
	EquipWeapon(Game::GetInstance()->_inventory.GetWeaponByName(elem.Attribute("_weapon")));
}
