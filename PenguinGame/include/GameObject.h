//
// Created by edgar on 23/03/18.
//

#ifndef SRC_GAMEOBJECT_H
#define SRC_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include <memory>
#include "Rect.h"
#include "Component.h"

using namespace std;

class Component;

class GameObject {
public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    shared_ptr<Component> GetComponent(std::string type);

    Rect box;

private:
    vector<std::shared_ptr<Component>> components;
    bool isDead;

};


#endif //SRC_GAMEOBJECT_H
