
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

using namespace std;

class Music {
public:
    Music();
    Music(string file);
    ~Music();
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(string file);
    bool IsOpen();

private:
    Mix_Music* music;
};


#endif //SRC_MUSIC_H