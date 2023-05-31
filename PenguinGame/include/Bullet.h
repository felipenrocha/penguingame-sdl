
#ifndef __BULLET_H__
#define __BULLET_H__

#define BULLET_TYPE "Bullet"

#include "Component.h"

class Bullet : public Component {
public:
    Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite);

    void Update(float dt) override;
    void Render() override;
    bool Is(string type) override;

    int getDamage();

private:
    Vec2 speed;
    float distanceLeft;
    int damage;

};


#endif