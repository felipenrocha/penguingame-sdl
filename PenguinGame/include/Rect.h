
#ifndef __RECT_H__
#define __RECT_H__


#include "Vec2.h"
class Rect
{	public:
		float x, y, w, h;
	Rect(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) {}
	Rect();
	bool Contains(float x, float y);

	~Rect() {}

};

#endif