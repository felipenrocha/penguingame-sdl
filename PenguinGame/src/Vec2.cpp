#include "../include/Vec2.h"
#include <math.h>

Vec2 Vec2::soma_vec(Vec2 v)  {
    return Vec2(v.x + x, v.y + y);
}

Vec2 Vec2::sub_vec(Vec2 v) {
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::mul_escalar_vec(float scalar)  {
    return Vec2(x * scalar, y * scalar);
}

float Vec2::magnitude() {
    return (float) sqrt(x * x + y * y);
}
Vec2 Vec2::GetRotated(float ang) {
    return Vec2((x * cos(ang)) - (y * sin(ang)), (y * cos(ang)) + (x * sin(ang)));
}

