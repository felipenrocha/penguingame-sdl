#include "../include/Resources.h"


std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(const std::string& file) {
    // verifica se a imagem já foi carregada
    auto it = imageTable.find(file);
    if (it != imageTable.end()) {
        return it->second; // retorna a imagem já carregada
    }
    // caso de imagem nao carregada:
    cout << "Imagem não encontrada, carregando arquivo.";
    // carrega a imagem
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
   // armazena a imagem no mapa
    imageTable.insert({ file, texture });
    return texture;
   


}

void Resources::ClearImages() {
    // libera a memória alocada para as imagens
    for (auto& pair : imageTable) {
        SDL_DestroyTexture(pair.second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(const std::string& file) {
    // verifica se a música já foi carregada
    auto it = musicTable.find(file);
    if (it != musicTable.end()) {
        return it->second; // retorna a música já carregada
    }
    //caso da musica nao carregada
    cout << "Música não encontrada, carregando arquivo.";
    // 
    // carrega a música
    Mix_Music* music = Mix_LoadMUS(file.c_str());

    // armazena a música no mapa
    musicTable.insert({ file , music });

    return music;
}

void Resources::ClearMusics() {
    // libera a memória alocada para as músicas
    for (auto& pair : musicTable) {
        Mix_FreeMusic(pair.second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(const std::string& file) {
    // verifica se o som já foi carregado
    auto it = soundTable.find(file);
    if (it != soundTable.end()) {
        return it->second; // retorna o som já carregado
    }
    //caso do som nao encontrado
    cout << "Imagem não encontrada, carregando arquivo.";

    // carrega o som

    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

    // armazena o som no mapa
    soundTable.insert({ file, chunk });

    return chunk;
}

void Resources::ClearSounds() {
    // libera a memória alocada para os sons
    for (auto& pair : soundTable) {
        Mix_FreeChunk(pair.second);
    }
    soundTable.clear();
}
