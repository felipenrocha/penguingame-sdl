
#ifndef __RECT_H__
#define __RECT_H__


#include "Vec2.h"
class Rect
{
public:
    float x, y, w, h;

    Rect();
    Rect(float x, float y, float w, float h);

    Rect SumVec2(Vec2 v);
    Rect SubVec2(Vec2 v);
    Vec2 CenterCoord();
    float DistRecs(Rect r);
    float DistVec2(Vec2 v);
    bool Contains(Vec2 v);

    Rect operator+=(Vec2 v);

};

#endif