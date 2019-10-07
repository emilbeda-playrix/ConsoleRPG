#include "Enemies.h"

Enemies::Enemies() {

}

Enemies::~Enemies() {
	
}

void Enemies::AddEnemy(const int x, const int y, const int health, const int attack, const int defence) {
	_enemyArray.emplace_back(std::make_shared<Enemy>(x, y, health, attack, defence));
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

void Enemies::Serialize(TiXmlElement& elem)
{
	for (const std::shared_ptr<Enemy> &enemy : _enemyArray)
	{
		if (enemy)
		{
			TiXmlElement* el = new TiXmlElement("Enemy");
			enemy->Serialize(*el);
			elem.LinkEndChild(el);
			
		}
	}
}
