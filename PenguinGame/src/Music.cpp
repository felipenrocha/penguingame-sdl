#include "../include/Music.h"



#include <iostream>

Music::Music() {
    // init null song
    music = nullptr;
}

Music::Music(string file) {
    /*
    O segundo construtor chama Open, o primeiro apenas inicializa music
    como nullptr, para aguardar uma chamada a Open vinda de fora da fun��o.
    */
    Open(file);
}

Music::~Music() {
    Stop(0);
    Mix_FreeMusic(music);
}

void Music::Play(int times) {
    

    /*
    
        Mix_PlayMusic recebe uma m�sica e quantas vezes ela deve ser tocada.
    Se loops for -1, a m�sica repete infinitamente. Se loops for 0, a m�sica n�o �
    tocada. Vale notar que a Mixer s� suporta uma m�sica sendo tocada por vez:
    Se outra m�sica j� estiver tocando, ela para.
   
    
    */
    // N�o se esque�a que SDL_Music pode ser nullptr.
    if (music == nullptr) {
        cout << "Nenhu8ma musica carregada: " << SDL_GetError() << endl;
        exit(1);
    }
 
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
    /*
        Mix_FadeOutMusic para a m�sica atual dando um efeito de fade, isto �,
    diminuindo gradualmente o volume at� chegar em 0. O tempo para a m�sica
    parar totalmente � passado como argumento da fun��o, em milissegundos.
    Vamos deixar default como 1,5 segundos. Caso queria que pare
    imediatamente, basta passar 0 como argumento.*/

    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
    /*
    Carrega a m�sica indicada no arquivo file. 
    */
    music = Mix_LoadMUS(file.c_str());

    // Lembre-se de tratar o caso em que nullptr � retornado.
    if (music == nullptr) {
        cout << "Erro ao carregar a musica: " << SDL_GetError() << endl;
        exit(1);
    }
}

bool Music::IsOpen() {
    //Checa se music � nula.
    if (music == nullptr) {
        return false;
    }
    return true;
}

