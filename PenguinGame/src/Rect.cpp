#include "../include/Rect.h"

Rect::Rect() : x(0), y(0), w(0), h(0) {}

bool Rect::Contains(float x, float y)
{
    if ((x >= this->x) && (x <= this->x + this->w))
    {
        if ((y >= this->y) && (y <= this->y + this->h))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }
}