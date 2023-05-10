#include "../include/Resources.h"


std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(const std::string& file) {
    // verifica se a imagem j� foi carregada
    auto it = imageTable.find(file);
    if (it != imageTable.end()) {
        return it->second; // retorna a imagem j� carregada
    }
    // caso de imagem nao carregada:
    cout << "Imagem n�o encontrada, carregando arquivo.";
    // carrega a imagem
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
   // armazena a imagem no mapa
    imageTable.insert({ file, texture });
    return texture;
   


}

void Resources::ClearImages() {
    // libera a mem�ria alocada para as imagens
    for (auto& pair : imageTable) {
        SDL_DestroyTexture(pair.second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(const std::string& file) {
    // verifica se a m�sica j� foi carregada
    auto it = musicTable.find(file);
    if (it != musicTable.end()) {
        return it->second; // retorna a m�sica j� carregada
    }
    //caso da musica nao carregada
    cout << "M�sica n�o encontrada, carregando arquivo.";
    // 
    // carrega a m�sica
    Mix_Music* music = Mix_LoadMUS(file.c_str());

    // armazena a m�sica no mapa
    musicTable.insert({ file , music });

    return music;
}

void Resources::ClearMusics() {
    // libera a mem�ria alocada para as m�sicas
    for (auto& pair : musicTable) {
        Mix_FreeMusic(pair.second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(const std::string& file) {
    // verifica se o som j� foi carregado
    auto it = soundTable.find(file);
    if (it != soundTable.end()) {
        return it->second; // retorna o som j� carregado
    }
    //caso do som nao encontrado
    cout << "Imagem n�o encontrada, carregando arquivo.";

    // carrega o som

    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

    // armazena o som no mapa
    soundTable.insert({ file, chunk });

    return chunk;
}

void Resources::ClearSounds() {
    // libera a mem�ria alocada para os sons
    for (auto& pair : soundTable) {
        Mix_FreeChunk(pair.second);
    }
    soundTable.clear();
}
