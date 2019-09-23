#pragma once
#include <iostream>
#include <windows.h>

#define WIDTH 120
#define HEIGHT 40


using namespace std;

class Console {
private:


public:
	HANDLE wHnd;
	HANDLE rHnd;
	static Console& Get() {
		static Console instance;
		return instance;
	}
	Console();
	~Console();
	void consoleInit();
	void moveCursor(int x, int y);
	char getChar(int x, int y);
	void setColor(WORD color);
};

