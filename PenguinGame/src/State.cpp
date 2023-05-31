#include "../include/State.h"
#include "../include/GameObject.h"

#include "../include/Vec2.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"
#include "../include/Alien.h"


#define BACKGROUND_SPRITE_PATH "assets/img/ocean.jpg"
#define BACKGROUND_MUSIC_PATH "assets/audio/stageState.ogg"
#define BACKGROUND_MUSIC_LOOP_TIMES -1 // -1 for infinite loop
#define ENEMY_SOUND_PATH "assets/audio/boom.wav"
#define PI 3.141592

#define TILE_WIDTH 64
#define TILE_HEIGHT 64


State::State() {
    started = false;
    quitRequested = false;

    auto bg(new GameObject);
    bg->AddComponent(new CameraFollower(*bg));
    bg->AddComponent(new Sprite(*bg, "assets/img/ocean.jpg"));

    objectArray.emplace_back(bg);

    auto map(new GameObject);
    map->box.w = 1024;
    map->box.h = 600;

    TileSet* tileSet = new TileSet(TILE_WIDTH, TILE_HEIGHT, "assets/img/tileset.png");
    TileMap* tileMap = new TileMap(*map, "assets/map/tileMap.txt", tileSet);
    map->AddComponent(tileMap);
    objectArray.emplace_back(map);

    auto alien(new GameObject);
    Rect& alienBox = alien->box;
    alienBox += {512 + alienBox.w / 2, 300 + alienBox.h / 2};
    alien->AddComponent(new Alien(*alien, 5));
    objectArray.emplace_back(alien);

}

State::~State() {
    objectArray.clear();
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {
    music.Open("assets/audio/stageState.ogg");
}

void State::Update(float dt) {
    InputManager inputManager = InputManager::GetInstance();

    Camera::Update(dt);

    quitRequested = inputManager.KeyPress(ESCAPE_KEY) || inputManager.QuitRequested();

    for (int i = 0; i < objectArray.size(); i++) {
        objectArray[i].get()->Update(dt);
    }

    for (int i = 0; i < objectArray.size(); i++) {
        if (objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render() {
    for (auto& it : objectArray) {
        it->Render();
    }
}

void State::Start() {
    LoadAssets();
    music.Play();
    for (auto& i : objectArray) {
        i->Start();
    }
    started = true;
}

weak_ptr<GameObject> State::AddObject(GameObject* go) {
    shared_ptr<GameObject> gameObject(go);
    objectArray.push_back(gameObject);
    if (started) {
        gameObject->Start();
    }
    return weak_ptr<GameObject>(gameObject);
}

weak_ptr<GameObject> State::GetObjectPtr(GameObject* go) {
    for (auto& i : objectArray) {
        if (i.get() == go) {
            return weak_ptr<GameObject>(i);
        }
    }
    return weak_ptr<GameObject>();
}

