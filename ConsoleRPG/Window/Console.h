#pragma once
#include <iostream>
#include <windows.h>

#define WIDTH 120
#define HEIGHT 40

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
	
	void MoveCursor(const int x, const int y) const;
	char GetChar(const int x, const int y) const;
	void SetColor(const WORD color) const ;
	
	void Print(const int x, const int y, const std::string& text, const int color) const;
};

