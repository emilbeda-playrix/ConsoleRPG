#include "Enemies.h"

Enemies::Enemies() {

}

Enemies::~Enemies() {
	
}

void Enemies::RemoveDefeated()
{
	int place = 0;
	for (const std::shared_ptr<Enemy> &enemy : _enemyArray)
	{
		if(enemy && enemy->GetDefeated())
		{
			_enemyArray.erase(_enemyArray.begin() + place);
		}
		++place;
	}
}

Enemy* Enemies::GetEnemyOnPlace(Point& place) {
	for (const std::shared_ptr<Enemy> &enemy : _enemyArray) {
		if (enemy->GetPosition() == place) {
			return enemy.get();
		}
	}
	return nullptr;
}

void Enemies::Serialize(tinyxml2::XMLElement& elem)
{
	
}

void Enemies::Serialize(tinyxml2::XMLElement& elem, tinyxml2::XMLDocument& doc)
{
	for (const std::shared_ptr<Enemy> &enemy : _enemyArray)
	{
		if (enemy)
		{
			tinyxml2::XMLElement* el = doc.NewElement("Enemy");
			enemy->Serialize(*el);
			elem.LinkEndChild(el);
			
		}
	}
}

void Enemies::Deserialize(tinyxml2::XMLElement& elem)
{
	_enemyArray.emplace_back(std::make_shared<Enemy>());
	(dynamic_cast<Enemy*>(_enemyArray.back().get()))->Deserialize(elem);
}
