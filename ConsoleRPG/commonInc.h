#pragma once
#include <iostream>
#include <string>
#include "Console.h"
using namespace std;

struct Position {
	int X;
	int Y;
	/*inline bool operator==(const position& p1, const position& p2) {
		return p1.x == p2.x && p1.y == p2.y;
	}*/
};

enum itemTypes { POTION = 0, WEAPON = 1, ARMOR = 2};

