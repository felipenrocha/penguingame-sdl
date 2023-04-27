
#include "../include/Sprite.h"
//#include "Music.h"
#include "../include/State.h"

State::State() {
    // add sprite to game object
    GameObject* go = new GameObject();
    go->AddComponent(new Sprite(*go, "assets/img/ocean.jpg"));
    // unique ptr

    objectArray.emplace_back(go);


    LoadAssets();


    quitRequested = false;
	

    this->music->Play();

}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {
    music = new Music("assets/audio/stageState.ogg");

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
    /*O corpo dessa fun��o est� dispon�vel no Moodle. Podem ser
necess�rios alguns ajustes nele para se adequar aos nomes de vari�veis ou
fun��es do seu c�digo. Al�m disso, voc� pode tirar a chamada �
SDL_QuitRequested em Update(), j� que Input cuida de eventos de
SDL_QUIT para n�s.
*/
void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;
	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contr�rio
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para termina��o
		if (event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de tr�s pra frente pra sempre clicar no objeto mais de cima
			for (int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro � algo que devemos evitar ao m�ximo.
				// O prop�sito do unique_ptr � manter apenas uma c�pia daquele ponteiro,
				// ao usar get(), violamos esse princ�pio e estamos menos seguros.
				// Esse c�digo, assim como a classe Face, � provis�rio. Futuramente, para
				// chamar fun��es de GameObjects, use objectArray[i]->fun��o() direto.

				if (go->box.Contains({ (float)mouseX, (float)mouseY })) {
						Face* face = (Face*)go->GetComponent("Face");
					if (nullptr != face) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// faz o baulho:
						Sound* sound = (Sound*) go->GetComponent("Sound");
						if(sound != nullptr)
							sound->Play();
						// Sai do loop (s� queremos acertar um)
						break;
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}
			// Se n�o, crie um objeto
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
	go->AddComponent(sprite);

	//add new sound object
	go->AddComponent(new Sound(*go, "assets/audio/boom.wav"));
	go->AddComponent(new Face(*go));

	objectArray.emplace_back(go);
	printf("in");

}