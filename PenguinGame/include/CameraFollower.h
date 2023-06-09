#ifndef __CAMERA_FOLLOWER_H__
#define __CAMERA_FOLLOWER_H__

#pragma once

#include <iostream>

#include "Component.h"
#include "GameObject.h"

class CameraFollower : public Component
{
public:
    CameraFollower(GameObject& associated);
    void Update(float dt);
    void Render();
    void Start() override;
    bool Is(std::string type);
};

#endif