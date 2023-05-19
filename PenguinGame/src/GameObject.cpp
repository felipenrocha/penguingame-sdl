#include <algorithm>
#include "../include/GameObject.h"

GameObject::GameObject() : box(0, 0, 0, 0),
isDead(false)
{
}

GameObject::~GameObject()
{

    components.clear();
}

void GameObject::Update(float dt)
{
    for (int i = components.size() - 1; i >= 0; --i)
    {
        components[i]->Update(dt);
    }
}

void GameObject::Render()
{
    for (int i = components.size() - 1; i >= 0; --i)
    {
        components[i]->Render();
    }
}

bool GameObject::IsDead()
{
    return isDead;
}

void GameObject::RequestDelete()
{
    isDead = true;
}


void GameObject::AddComponent(Component* cpt) {
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
    for (unsigned int i = 0; i < components.size(); i++) {
        if (components[i].get() == cpt) {
            components.erase(components.begin() + i);
            break;
        }
    }
}

std::shared_ptr<Component> GameObject::GetComponent(std::string type)
{
    for (int i = components.size() - 1; i >= 0; i--)
    {
        if (components[i]->Is(type))
        {
            return components[i];
        }
    }
    return nullptr;
}