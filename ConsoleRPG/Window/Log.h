#pragma once
#include "../Common/commonInc.h"

constexpr int LOG_X = 0;
constexpr int LOG_Y = 34;

class Log : public Drawable
{
private:
	std::vector<std::string> _logArray;
public:
	static Log& GetInstance() {
		static Log instance;
		return instance;
	}
	Log();
	~Log();
	void Init();
	void Add(std::string text);
	void Clear();
	void Render() override;
};

