
#ifndef __SOUND_H__
#define __SOUND_H__


#include "Component.h"
#include <SDL_mixer.h>

class Sound : public Component {
public:
    explicit Sound(GameObject& associated);
    Sound(GameObject& associated, string file);
    ~Sound() override;

    void Play(int times = 1);
    void Stop(int msToStop = 1500);
    void Open(string file);
    bool IsOpen();

    void Update(float dt) override;
    void Render() override;
    bool Is(string type) override;

private:
    Mix_Chunk* chunk;
    int channel;


};


#endif //SRC_SOUND_H
