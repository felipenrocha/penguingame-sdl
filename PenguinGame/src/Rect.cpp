#include "../include/Rect.h"

Rect::Rect() : x(0), y(0), w(0), h(0) {}

bool Rect::Contains(Vec2 v) {
    return (v.x < (x + w) && v.x >= x) && (v.y < (y + h) && v.y >= y);
}