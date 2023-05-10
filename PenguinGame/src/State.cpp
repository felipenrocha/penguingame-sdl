
#include "../include/Sprite.h"
//#include "Music.h"
#include "../include/State.h"
#define TILE_WIDTH 64
#define TILE_HEIGHT 64
#define BACKGROUND_SPRITE_PATH "assets/img/ocean.jpg"


State::State() {
	

	GameObject* background = new GameObject();
	// Criando o sprite do background
	shared_ptr<GameObject> go = std::shared_ptr<GameObject>(new GameObject());
	go->box.x = 0;
	go->box.y = 0;
	Sprite* sp = new Sprite(*go, "assets/img/ocean.jpg");
	go->AddComponent((shared_ptr<Sprite>)sp);
	objectArray.emplace_back(std::move(go));

	// Adicionando o background no objectArray
	objectArray.emplace_back(background);


	GameObject* map = new GameObject();
	// Criando o tileSet para o tileMap
	TileSet* tileSet = new TileSet(*map, TILE_HEIGHT, TILE_WIDTH, MAP_TILESET_PATH);
	// Criando o tileMap
	TileMap* tileMap = new TileMap(*map, MAP_TILEMAP_PATH, tileSet);
	map->AddComponent((std::shared_ptr<TileMap>)tileMap);
    //initial x,y
	map->box.x = 0;
	map->box.y = 0;

	// Adicionando o mapa no objectArray
	objectArray.emplace_back(map);




	// adicionando BGM
    Music* music = new Music();
    music->Open("assets/audio/stageState.ogg");
    music->Play();




    quitRequested = false;
	


}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {
   // music = new Music("assets/audio/stageState.ogg");

}

void State::Update(float dt) {

	Input();
	for (int i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Update(dt);
	}

	for (int i = 0; i < objectArray.size(); i++) {
		if (objectArray[i]->IsDead()) {
			objectArray.erase(objectArray.begin() + i);
		}
	}


}

void State::Render() {
    for (auto it = objectArray.begin(); it != objectArray.end(); ++it) {
        (*it)->Render();
    }
}

State::~State() {
//    Esvazia o array de objetos(clear).
    objectArray.clear();

}
    /*O corpo dessa função está disponível no Moodle. Podem ser
necessários alguns ajustes nele para se adequar aos nomes de variáveis ou
funções do seu código. Além disso, você pode tirar a chamada à
SDL_QuitRequested em Update(), já que Input cuida de eventos de
SDL_QUIT para nós.
*/
void State::Input() {
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event))
    {
        // Se o evento for quit, setar a flag para terminação
        if (event.type == SDL_QUIT)
        {
            quitRequested = true;
        }

        // Se o evento for clique...
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for (int i = int(objectArray.size()) - 1; i >= 0; --i)
            {
                // Obtem o ponteiro e casta pra Face.
                GameObject* go = (GameObject*)objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

  
                if (go->box.Contains(float(mouseX), float(mouseY)))
                {
                    Face* face = (Face*)go->GetComponent("Face").get();
                    if (nullptr != face)
                    {
                        int damage = rand() % 10 + 10;
                        // Aplica dano
                        face->Damage(damage);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_KEYDOWN)
        {
            // Se a tecla for ESC, setar a flag de quit
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quitRequested = true;
            }
			else {
				Vec2 objPos = (Vec2(200, 0).GetRotated((float)(-M_PI + M_PI * (rand() % 1001) / 500.0))).soma_vec(Vec2(mouseX, mouseY));
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}


void State::AddObject(int mouseX, int mouseY) {
	// add new sprite object
	GameObject* go = new GameObject();
	Sprite* sprite = new Sprite(*go, "assets/img/penguinface.png");

	go->box.x = mouseX - go->box.w / 2;
	go->box.y = mouseY - go->box.h / 2;
	go->AddComponent((shared_ptr<Sprite>)sprite);

	//add new sound object
    Sound* sound = new Sound(*go, "assets/audio/boom.wav");
	go->AddComponent((shared_ptr<Sound>)sound);
    Face* face = new Face(*go);
	go->AddComponent((shared_ptr<Face>)face);

    objectArray.emplace_back(go);

}