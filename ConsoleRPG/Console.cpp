#include "Console.h"
Console::Console() {

}
Console::~Console() {

}
void Console::consoleInit() {
	SMALL_RECT consoleWriteArea = { 0,0, WIDTH - 1, HEIGHT - 1 };
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &consoleWriteArea);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(wHnd, &cursorInfo);
}

void Console::moveCursor(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(wHnd, coord);
}

char Console::getChar(int x, int y) {
	char c = '\0';
	COORD coord;
	coord.X = x;
	coord.Y = y;
	DWORD read = 0;
	if (!ReadConsoleOutputCharacterA(wHnd, &c, 1, coord, &read) || read != 1)
		c = '\0';
	return c;
}

void Console::setColor(WORD color) {
	SetConsoleTextAttribute(wHnd, color);
}