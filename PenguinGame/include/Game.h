#pragma once
#ifndef GAME_H
#define GAME_H



#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include "State.h"

#define ASSETS_PATH "assets/"
using namespace std;
const string GAME_TITLE = "Felipe N. Rocha - 17/0050084";
const int GAME_WIDTH = 1024;
const int GAME_HEIGHT = 600;


class Game {

public:
    Game(string title, int width, int height);
    Game(Game&&) = default;
    ~Game();

    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();

private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;

};

#endif
