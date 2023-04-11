
#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

using namespace std;

class Sprite {

public:
    Sprite();
    Sprite(string file);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth() const { return this->width; }
    int GetHeight() const { return this->height; };
    bool IsOpen() { return texture != nullptr; }

private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

};


#endif //SRC_SPRITE_H