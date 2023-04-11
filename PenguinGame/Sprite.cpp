#include "Sprite.h"
#include "Game.h"


Sprite::Sprite() {
    // Seta texture como nullptr (imagem não carregada).
    this->texture = nullptr;
}

Sprite::Sprite(string file) {
    // Seta texture como nullptr.Em seguida, chama Open
    texture = nullptr;
    // initialize everything:
    Open(file);
}

Sprite::~Sprite() {
    /*Se houver imagem alocada, desaloca. Nunca use delete ou free em
    uma SDL_Texture. Use SDL_DestroyTexture(SDL_Texture*)*/
    if (IsOpen()) {
        SDL_DestroyTexture(texture);
    }

}
void Sprite::Open(string file) {
    /*Antes de carregar, devese checar se já há alguma imagem carregada em texture: Se sim, deve ser
    desalocada primeiro.*/
    if (IsOpen()) {
        SDL_DestroyTexture(texture);
    }

    // get renderer
    SDL_Renderer *renderer = Game::GetInstance().GetRenderer();

    //Carrega a imagem indicada pelo caminho file.
    texture = IMG_LoadTexture(renderer, file.c_str());
    // checar se já há alguma imagem carregada em texture
    if (texture == nullptr) {
        cout << "Erro ao carregar textura: " << SDL_GetError() << endl;
        exit(1);
    }

    //Com a textura carregada, precisamos descobrir suas dimensões:
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    // Por último, sete o clip com as dimensões da imagem, usando..
    SetClip(0, 0, GetWidth(), GetHeight());
}

void Sprite::Render(int x, int y) {
     // Render é um wrapper para SDL_RenderCopy, que recebe quatro argumentos.
    // renderer:
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    // rect:
    SDL_Rect dst = { x, y, width, height };
    printf("in");

    SDL_RenderCopy(renderer, texture, &clipRect, &dst);
}


void Sprite::SetClip(int x, int y, int w, int h) {
    // Seta clipRect com os parâmetros dados
    clipRect.x = x; 
    clipRect.y = y;
    clipRect.h = h; 
    clipRect.w = w;
}
