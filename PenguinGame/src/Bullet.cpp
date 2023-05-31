#include "../include/Bullet.h"
#include "../include/Sprite.h"


Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite) : Component(associated) {
    associated.AddComponent(new Sprite(associated, move(sprite)));
    this->speed = Vec2(speed, 0).Rotate(angle);
    this->distanceLeft = maxDistance;
}

void Bullet::Update(float dt) {
    associated.box += speed * dt;
    distanceLeft -= (speed * dt).Mag();
    if (distanceLeft < 0) {
        associated.RequestDelete();
    }
}

void Bullet::Render() {}

bool Bullet::Is(string type) {
    return type == BULLET_TYPE;
}

int Bullet::getDamage() {
    return damage;
}