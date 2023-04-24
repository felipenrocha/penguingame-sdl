#include "../include/Vec2.h"
#include <math.h>

Vec2 soma_vec(const Vec2& v1, const Vec2& v2)  {
    return Vec2(v1.x + v2.x, v1.y + v2.y);
}

Vec2 sub_vec(const Vec2& v1, const Vec2& v2) {
    return Vec2(v1.x - v2.x, v1.y - v2.y);
}

Vec2 mul_escalar_vec(const Vec2& v, float scalar)  {
    return Vec2(v.x * scalar, v.y * scalar);
}

float Vec2::magnitude() {
    return (float) sqrt(x * x + y * y);
}