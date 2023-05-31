#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <iostream>
#include "GameObject.h"

using namespace std;

class GameObject;

class Component {
public:
    Component(GameObject& associated);
    virtual ~Component();

    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(string type) = 0;

    virtual void Start();

protected:
    GameObject& associated;

};



#endif //SRC_COMPONENT_H
