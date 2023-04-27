#include "../include/Sound.h"


Sound::Sound(GameObject& associated) : Component(associated) {
    /*Atribui o associated ao atributo de mesmo nome e atribui nullptr a
chunk*/

    chunk = nullptr;
    channel = 0;
}

Sound::Sound(GameObject& associated, string file) : Component(associated) {
    /*Chama o outro construtor(esse é um dos usos da initializer list) e
depois chama Open passando a string recebida.*/
    chunk = nullptr;
    channel = 0;
    Open(file);
}
Sound::~Sound() {
    /*Se chunk for diferente de nullptr, chame Halt e depois desaloque o
som usando o Mix_FreeChunk.*/
    if (chunk != nullptr) {
        Mix_HaltChannel(channel);
       }

    Mix_FreeChunk(chunk);
}
void Sound::Open(string file) {
  /*/  Abre o arquivo chamando o MIX_Load.Lembre - se de tratar o caso em
        que a abertura do arquivo falha!*/
    chunk = Mix_LoadWAV((file).c_str());
    if (chunk == nullptr) {
        cout << "Erro ao carregar o som: " << SDL_GetError() << endl;
        exit(1);
    }
}

void Sound::Stop(int msToStop) {
   /* Mix_HaltChannel para um canal específico, ou, se receber - 1, para
        todos.Use o número que Mix_PlayChannel te retornou.Pare o canal no qual
        o chunk correspondente está tocando, mas só faça isso se chunk for
        diferente de nullptr*/
    // -1 setado como default na assinatura
    
    if (chunk != nullptr) {
        Mix_HaltChannel(channel);
    }
}


void Sound::Play(int times) {
    channel = Mix_PlayChannel(-1, chunk, times - 1);
    if (channel == -1) {
        cout << "Erro ao carregar o som: " << SDL_GetError() << endl;
        exit(1);
    }

}
void Sound::Update(float dt) {}

void Sound::Render() {}

bool Sound::Is(string type) {
    return type == "Sound";
}

