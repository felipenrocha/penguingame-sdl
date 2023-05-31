#include "../include/Resources.h"


unordered_map<string, SDL_Texture*> Resources::imageTable;
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(string file) {
    if (imageTable.find(file) == imageTable.end()) {
        auto texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), (file).c_str());
        if (texture == nullptr) {
            cout << "Unable to load texture: " << SDL_GetError() << endl;
            exit(1);
        }
        imageTable.insert(make_pair(file, texture));
        return texture;
    }
    return (*imageTable.find(file)).second;
}

void Resources::ClearImages() {
    for (auto& iT : imageTable) {
        SDL_DestroyTexture(iT.second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(string file) {
    if (musicTable.find(file) == musicTable.end()) {
        auto music = Mix_LoadMUS((file).c_str());
        if (music == nullptr) {
            cout << "Unable to load music: " << SDL_GetError() << endl;
            exit(1);
        }
        musicTable.insert(make_pair(file, music));
        return music;
    }
    return (*musicTable.find(file)).second;
}

void Resources::ClearMusics() {
    for (auto& mT : musicTable) {
        Mix_FreeMusic(mT.second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(string file) {
    if (soundTable.find(file) == soundTable.end()) {
        auto chunk = Mix_LoadWAV((file).c_str());
        if (chunk == nullptr) {
            cout << "Unable to load sound: " << SDL_GetError() << endl;
            exit(1);
        }
        soundTable.insert(make_pair(file, chunk));
        return chunk;
    }
    return (*soundTable.find(file)).second;
}

void Resources::ClearSounds() {
    for (auto& sT : soundTable) {
        Mix_FreeChunk(sT.second);
    }
    soundTable.clear();
}


