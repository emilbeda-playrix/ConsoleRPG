#pragma once
#include <conio.h>
#include "../Common/commonInc.h"
class Events
{
private:
	
public:
	static Events& GetInstance()
	{
		static Events instance;
		return instance;
	}
	
	Events();
	~Events();
	
	int WaitKeyPress();
};