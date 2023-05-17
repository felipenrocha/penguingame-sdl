#ifndef __VEC_2_H__
#define __VEC_2_H__
#include <memory>

class Vec2
{
public:
	Vec2(int x, int y);
	Vec2();
	Vec2 GetRotated(float theta);
	float x, y;
	Vec2 operator+(const Vec2& other) const;
};

#endif