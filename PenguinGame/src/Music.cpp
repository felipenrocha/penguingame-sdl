#include "../include/Music.h"



#include <iostream>

Music::Music() {
    // init null song
    music = nullptr;
}

Music::Music(string file) {
    /*
    O segundo construtor chama Open, o primeiro apenas inicializa music
    como nullptr, para aguardar uma chamada a Open vinda de fora da função.
    */
    Open(file);
}

Music::~Music() {
    Stop(0);
    Mix_FreeMusic(music);
}

void Music::Play(int times) {
    

    /*
    
        Mix_PlayMusic recebe uma música e quantas vezes ela deve ser tocada.
    Se loops for -1, a música repete infinitamente. Se loops for 0, a música não é
    tocada. Vale notar que a Mixer só suporta uma música sendo tocada por vez:
    Se outra música já estiver tocando, ela para.
   
    
    */
    // Não se esqueça que SDL_Music pode ser nullptr.
    if (music == nullptr) {
        cout << "Nenhu8ma musica carregada: " << SDL_GetError() << endl;
        exit(1);
    }
 
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
    /*
        Mix_FadeOutMusic para a música atual dando um efeito de fade, isto é,
    diminuindo gradualmente o volume até chegar em 0. O tempo para a música
    parar totalmente é passado como argumento da função, em milissegundos.
    Vamos deixar default como 1,5 segundos. Caso queria que pare
    imediatamente, basta passar 0 como argumento.*/

    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
    /*
    Carrega a música indicada no arquivo file. 
    */
    music = Mix_LoadMUS(file.c_str());

    // Lembre-se de tratar o caso em que nullptr é retornado.
    if (music == nullptr) {
        cout << "Erro ao carregar a musica: " << SDL_GetError() << endl;
        exit(1);
    }
}

bool Music::IsOpen() {
    //Checa se music é nula.
    if (music == nullptr) {
        return false;
    }
    return true;
}

