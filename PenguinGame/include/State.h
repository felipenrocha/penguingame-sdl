//
// Created by edgar on 16/03/18.
//

#ifndef STATE_H
#define STATE_H

#include "Sprite.h"
#include "Music.h"
#include "Face.h"

#include "Sound.h"

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
    Sprite *bg;
    Music *music;
    bool quitRequested;
    vector<unique_ptr<GameObject>> objectArray;


};


#endif //SRC_STATE_H
