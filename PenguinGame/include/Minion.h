
#ifndef __MINION_H__
#define __MINION_H__

#define MINION_TYPE "Minion"

#define MINION_ANGULAR_SPEED M_PI/8


#include "GameObject.h"

class Minion : public Component {
public:
    Minion(GameObject& associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);

    void Update(float dt) override;
    void Render() override;
    bool Is(string type) override;

    void  Shoot(Vec2 target);

private:
    GameObject& alienCenter;
    float arc;

    float float_rand(float min, float max);
};


#endif //SRC_MINION_H
