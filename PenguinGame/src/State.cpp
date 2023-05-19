#include "../include/State.h"
#include "../include/GameObject.h"
#include "../include/Face.h"
#include "../include/Vec2.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"

#define BACKGROUND_SPRITE_PATH "assets/img/ocean.jpg"
#define BACKGROUND_MUSIC_PATH "assets/audio/stageState.ogg"
#define BACKGROUND_MUSIC_LOOP_TIMES -1 // -1 for infinite loop

#define ENEMY_SPRITE_PATH "assets/img/penguinface.png"
#define ENEMY_SOUND_PATH "assets/audio/boom.wav"
#define PI 3.141592

#define TILE_WIDTH 64
#define TILE_HEIGHT 64


State::State() {
quitRequested = false;

// Background
std::shared_ptr<GameObject> go = std::shared_ptr<GameObject>(new GameObject());
go->box.x = 0;
go->box.y = 0;
Sprite* sp = new Sprite(*go, BACKGROUND_SPRITE_PATH);
CameraFollower* cmfl = new CameraFollower(*go);
go->AddComponent(sp);
go->AddComponent(cmfl);
objectArray.emplace_back(std::move(go));

// TileMap
std::shared_ptr<GameObject> gomp = std::shared_ptr<GameObject>(new GameObject());
gomp->box.x = 0;
gomp->box.y = 0;
TileSet* tlst = new TileSet(*gomp, 64, 64, "assets/img/tileset.png");
TileMap* tlmp = new TileMap(*gomp, "assets/map/tileMap.txt", tlst);
gomp->AddComponent(tlmp);
objectArray.emplace_back(std::move(gomp));

// BGM
music.Open(BACKGROUND_MUSIC_PATH);
music.Play(-1);
}

State::~State()
{
    objectArray.clear();
}

void State::LoadAssets()
{
}

void State::Update(float dt)
{
    // É importante que o Update da camera ocorra ANTES da atualização dos objetos
    // para que o background tenha sua movimentação compensada adequadamente.
    Camera::Update(dt);

    // Lida com eventos de quit a partir da interface de InputManager
    if ((InputManager::GetInstance().KeyPress(ESCAPE_KEY)) || (InputManager::GetInstance().QuitRequested()))
    {
        quitRequested = true;
    }
    if (InputManager::GetInstance().KeyPress(SPACEBAR_KEY))
    {
        Vec2 objPos = Vec2(200, 0).GetRotated(-PI + PI * (rand() % 1001) / 500.0) + Vec2(InputManager::GetInstance().GetMouseX(),
            InputManager::GetInstance().GetMouseY());
        AddObject((int)objPos.x - Camera::pos.x, (int)objPos.y - Camera::pos.y);
    }

    for (int i = (int)objectArray.size() - 1; i >= 0; --i)
    {
        objectArray[i]->Update(dt);
    }
    for (int i = (int)objectArray.size() - 1; i >= 0; --i)
    {
        if (objectArray[i]->IsDead())
        {
            objectArray.erase(objectArray.begin() + i);
        }
    }

    // delay frame
    SDL_Delay(dt);
}

void State::Render()
{
    for (int i = 0; i != (int)objectArray.size(); i++)
    {
        objectArray[i]->Render();
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::AddObject(int mouseX, int mouseY)
{
    std::shared_ptr<GameObject> go = std::shared_ptr<GameObject>(new GameObject());

    Sprite* sp = new Sprite(*go, ENEMY_SPRITE_PATH);
    go->box.x = mouseX - sp->GetWidth() / 2 + Camera::pos.x;
    go->box.y = mouseY - sp->GetHeight() / 2 + Camera::pos.y;
    go->AddComponent(sp);

    Sound* sd = new Sound(*go, ENEMY_SOUND_PATH);
    go->AddComponent(sd);

    Face* fc = new Face(*go);
    go->AddComponent(fc);

    objectArray.emplace_back(std::move(go));
}
