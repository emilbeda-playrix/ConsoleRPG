#pragma once
#include <iostream>
#include <string>
#include "../Window/Console.h"
#include <memory>
#include <vector>
#include "Drawable.h"

struct Point {
	int x;
	int y;
	inline bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}
};

enum class ItemTypes { Potion = 0, Weapon = 1, Armor = 2};

enum class PotionTypes { Heal = 1, Repair = 2 };

enum class Symbols { Player = '@', Enemy = 'E', Item = 'I' };

