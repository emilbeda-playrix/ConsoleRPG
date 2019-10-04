#pragma once
class Drawable
{
public:
	virtual void Render() = 0;
	bool _removeDrawable = false;
	bool GetRemoveDrawable() const { return _removeDrawable; }
};