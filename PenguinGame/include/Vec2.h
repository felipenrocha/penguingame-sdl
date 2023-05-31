#ifndef __VEC_2_H__
#define __VEC_2_H__
#include <memory>

class Vec2
{
public:
    float x, y;

    Vec2();
    Vec2(float x, float y);

    Vec2 Sum(Vec2 v);
    Vec2 Sub(Vec2 v);
    Vec2 Mul(const float escalar);

    float Mag();
    Vec2 Norm();
    float Dist(Vec2 v);

    float InclX();
    float Incl(Vec2 v);

    Vec2 Rotate(const float ang);

    Vec2 operator+(const Vec2& v);
    Vec2 operator-(const Vec2& v);
    Vec2 operator*(const float escalar);
    bool operator==(const Vec2& v);
    Vec2 operator+=(const Vec2& v);
    Vec2 operator-=(const Vec2& v);
};

#endif