#include "Log.h"
#include "../Game.h"

Log::Log()
{
	
}

Log::~Log()
{
	
}

void Log::Init()
{
	Game::GetInstance()->AddDrawable(this);
}


void Log::Add(std::string text)
{
	_logArray.emplace_back(text);
}

void Log::Clear()
{
	_logArray.clear();
}


void Log::Render()
{
	int logY = LOG_Y;
	
	for (auto &item : _logArray)
	{
		Console::GetInstance().Print(LOG_X, logY++, item, 10);
	}
}
