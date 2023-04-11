
#include "Sprite.h"
//#include "Music.h"
#include "State.h"

State::State() {
    
    LoadAssets();
    quitRequested = false;
    this->music->Play();
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {
    // generate bg (static for now)

    bg = new Sprite("assets/img/ocean.jpg");
    music = new Music("assets/audio/stageState.ogg");

}

void State::Update(float dt) {
    quitRequested = SDL_QuitRequested();

}

void State::Render() {
    this->bg->Render(0, 0);
}

State::~State() {

}