
#include "../include/Sprite.h"
//#include "Music.h"
#include "../include/State.h"

State::State() {

    GameObject* go = new GameObject();
    go->AddComponent(new Sprite(*go, "img/ocean.jpg"));
    objectArray.emplace_back(go);


    LoadAssets();
    quitRequested = false;
    this->music->Play();
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {
    music = new Music("audio/stageState.ogg");

}

void State::Update(float dt) {
    quitRequested = SDL_QuitRequested();

}

void State::Render() {
    for (auto it = objectArray.begin(); it != objectArray.end(); ++it) {
        (*it)->Render();
    }
}

State::~State() {

}