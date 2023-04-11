#include "Game.h"

Game* Game::instance = nullptr;


Game& Game::GetInstance() {
	if (instance == nullptr) {
		// No instance of Game;
		// Create game
		return *new Game(GAME_TITLE, GAME_WIDTH, GAME_HEIGHT);
	}

    return *instance;

}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}


State& Game::GetState() {
    return *state;
}
Game::Game(string title, int width, int height) {
	if (instance == nullptr) {
		instance = this;


        // sdl init

        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
            cout << "Erro SDL_Init: " << SDL_GetError() << endl;
            exit(1);
        }

        // TIF NOT WORKING
        // img init
        int initIMG = IMG_Init((IMG_INIT_JPG | IMG_INIT_PNG));
        if ((initIMG & (IMG_INIT_JPG | IMG_INIT_PNG)) != (IMG_INIT_JPG | IMG_INIT_PNG)) {
            cout << "Erro IMG_Init: " << SDL_GetError() << endl;
            exit(1);
        }
        
        //mix init
        int initMIX = Mix_Init((MIX_INIT_MP3 | MIX_INIT_OGG));
        if ((initMIX & (MIX_INIT_MP3 | MIX_INIT_OGG)) != (MIX_INIT_MP3 | MIX_INIT_OGG)) {
            cout << "Erro Mix_Init: " << SDL_GetError() << endl;
            exit(1);
        }

        if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
            cout << "Erro Mix_OpenAudio: " << SDL_GetError() << endl;
            exit(1);
        }

          //ttf init
        if (TTF_Init() != 0) {
            cout << "Erro TTF_Init: " << SDL_GetError() << endl;
            exit(1);
        }
     
        // window pointer
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
            0);
        if (window == nullptr) {
            cout << "Erro na criacao de janela: " << SDL_GetError() << endl;
            exit(1);
        }

        //Cria o renderizador
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            cout << "Erro na criacao do renderer: " << SDL_GetError() << endl;
            exit(1);
        }

        // state init

        state = new State();
	}
	else {
        //singleton error
		printf("Erro na criacao do jogo;");
		exit(1);
	}

}

/*

get state

*/


void Game::Run() {
    // game loop

        /*
        1. Verifica, controla e carrega as telas de jogo;
        2. Os dados de input são recebidos e processados;
        3. Os objetos tem seus respectivos estados (posição, HP...)
        atualizados;
        4. Os objetos são desenhados na tela.
        */
        // cout << "in";
    while (!GetState().QuitRequested()) {

        GetState().Update(0);
        GetState().Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    printf("out");

}
