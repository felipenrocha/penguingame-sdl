
#ifndef __STATE_H__
#define __STATE_H__



#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "TileMap.h"
#include "TileSet.h"
#include "Sound.h"
#define MAP_TILEMAP_PATH "assets/map/tileMap.txt"
#define MAP_TILESET_PATH "assets/img/tileset.png"

class State {
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Input();
    void AddObject(int mouseX, int mouseY);
    void Update(float dt);
    void Render();

private:
    bool quitRequested;
    vector<shared_ptr<GameObject>> objectArray;


};


#endif //SRC_STATE_H
