#ifndef __RESOURCES_H__
#define __RESOURCES_H__
#include <unordered_map>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include "Game.h"

class Resources {
public:
    static SDL_Texture* GetImage(string file);
    static void ClearImages();

    static Mix_Music* GetMusic(string file);
    static void ClearMusics();

    static Mix_Chunk* GetSound(string file);
    static void ClearSounds();

private:
    static std::unordered_map<std::string, SDL_Texture*> imageTable;
    static std::unordered_map<std::string, Mix_Music*> musicTable;
    static std::unordered_map<std::string, Mix_Chunk*> soundTable;
};

#endif