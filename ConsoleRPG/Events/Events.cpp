#include "Events.h"


Events::Events()
{
	
}

Events::~Events()
{
	
}

int Events::WaitKeyPress()
{
	int keyPressed = 0;

	switch (_getch())
	{
		case 'w':
		case 'W':
		case static_cast<char>(72) :
			keyPressed = static_cast<int>(KeyPressed::KeyUp);
			break;
		case 's':
		case 'S':
		case static_cast<char>(80) :
			keyPressed = static_cast<int>(KeyPressed::KeyDown);
			break;
		case 'a':
		case 'A':
		case static_cast<char>(75) :
			keyPressed = static_cast<int>(KeyPressed::KeyLeft);
			break;
		case 'd':
		case 'D':
		case static_cast<char>(77) :
			keyPressed = static_cast<int>(KeyPressed::KeyRight);
			break;
		case 'i':
		case 'I':
			keyPressed = static_cast<int>(KeyPressed::KeyInventory);
			break;
		case static_cast<char>(13) :
			keyPressed = static_cast<int>(KeyPressed::KeyReturn);
			break;
		case static_cast<char>(27) :
			keyPressed = static_cast<int>(KeyPressed::KeyEscape);
			break;
		default:
			break;
	}
	return keyPressed;
}

