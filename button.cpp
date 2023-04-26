#include "all.h"

//Button Button::instance_;

void Button::init(ButtonType btnType, float x, float y, float w, float h)
{
	buttontype = btnType;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Button::position()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(GameLib::window::getHwnd(), &pt);

	float top = y;
	float left = x;
	float bottom = y + h;
	float right = x + w;

#if 0
	onCursol = false;
	if (top < pt.y && bottom > pt.y)
		if (right < pt.x && left > pt.x)
			onCursol = true;
	return onCursol;
#else
	if (top > pt.y) return (onCursol = false);
	if (pt.y > bottom) return (onCursol =  false);
	if (pt.x > right) return (onCursol = false);
	if (left > pt.x) return (onCursol = false);
	return (onCursol = true);
#endif
}

void Button::render()
{
	rect(x, y, w, h, 0, 0, 0, onCursol ? 1.0f : 0.3f, 0.2f, 0.1f);
}


