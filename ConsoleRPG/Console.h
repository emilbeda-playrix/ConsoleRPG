#pragma once
#include <iostream>
#include <windows.h>

#define WIDTH 120
#define HEIGHT 40


using namespace std;

class Console {
private:
	HANDLE _wHnd;
	HANDLE _rHnd;
public:
	static Console& GetInstance() {
		static Console instance;
		return instance;
	}
	Console();
	~Console();
	void MoveCursor(int x, int y);
	char GetChar(const int x, const int y) const;
	void SetColor(const WORD color) const ;
};

