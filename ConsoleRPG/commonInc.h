#pragma once
#include <iostream>
#include <string>
#include "Console.h"
using namespace std;

struct Point {
	int x;
	int y;
	inline bool operator==(const Point& other) {
		return x == other.x && y == other.y;
	}
};

enum itemTypes { POTION = 0, WEAPON = 1, ARMOR = 2};

