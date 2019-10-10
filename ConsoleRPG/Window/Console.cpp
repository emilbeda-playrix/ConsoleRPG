#include "Console.h"

Console::Console() {
	SMALL_RECT consoleWriteArea = { 0,0, WIDTH - 1, HEIGHT - 1 };
	_wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	_rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleWindowInfo(_wHnd, TRUE, &consoleWriteArea);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(_wHnd, &cursorInfo);
}

Console::~Console() {

}

void Console::MoveCursor(const int x, const int y) const {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(_wHnd, coord);
}

char Console::GetChar(const int x, const int y) const {
	char c = '\0';
	COORD coord;
	coord.X = x;
	coord.Y = y;
	DWORD read = 0;
	if (!ReadConsoleOutputCharacterA(_wHnd, &c, 1, coord, &read) || read != 1)
		c = '\0';
	return c;
}

void Console::SetColor(const WORD color) const {
	SetConsoleTextAttribute(_wHnd, color);
}

void Console::Print(const int x, const int y, const std::string& text, const int color) const
{
	MoveCursor(x, y);
	SetColor(static_cast<WORD>(color));
	std::cout << text.c_str();
}
