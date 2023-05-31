#include "../include/InputManager.h"
#include "../include/Camera.h"
InputManager::InputManager() :
    mouseState{ false, false, false, false, false, false },
    mouseUpdate{ 0, 0, 0, 0, 0, 0 },
    quitRequested(false),
    updateCounter(0),
    mouseX(0),
    mouseY(0)
{
    
}
InputManager::~InputManager()
{
}
Vec2 InputManager::GetMouse() {
    return { mouseX + Camera::pos.x, mouseY + Camera::pos.y };
}
void InputManager::Update()
{
    SDL_Event event;

    // Atualiza a posi��o do mouse nos atributos da class
    SDL_GetMouseState(&mouseX, &mouseY);

    // Garante que, se um evento de quit n�o foi resolvido, o jogo continue rodando sem problemas
    // Ex.: O jogo esteja rodando com a flag de quit setada.
    quitRequested = false;

    //Atualiza o updateCounter
    updateCounter++;

    // Retorna TRUE se ocorrer eventos e processa a pilha de eventos
    while (SDL_PollEvent(&event))
    {
        // Garante que o mesmo evento n�o seja gravado repetidamente
        if (event.key.repeat != true)
        {
            // Switch que lida com os tipos de evento
            switch (event.type)
            {
                // Evento de tecla pressionada
            case SDL_KEYDOWN:
                // event.key.keysym.sym guarda a tecla em que ocorreu o evento
                keyState[event.key.keysym.sym] = true;
                keyUpdate[event.key.keysym.sym] = updateCounter;
                break;

                // Evento de soltura de tecla
            case SDL_KEYUP:
                // event.key.keysym.sym guarda a tecla em que ocorreu o evento
                keyState[event.key.keysym.sym] = false;
                keyUpdate[event.key.keysym.sym] = updateCounter;
                break;

            case SDL_MOUSEBUTTONDOWN:
                // event.button.button guarda o bot�o do mouse em que ocorreu o evento
                mouseState[event.button.button] = true;
                mouseUpdate[event.button.button] = updateCounter;
                break;

                // Evento de soltura do bot�o do mouse
            case SDL_MOUSEBUTTONUP:
                // event.button.button guarda o bot�o do mouse em que ocorreu o evento
                mouseState[event.button.button] = false;
                mouseUpdate[event.button.button] = updateCounter;
                break;

                // Evento de QUIT
            case SDL_QUIT:
                quitRequested = true;
                break;
            }
        }
    }
}



InputManager& InputManager::GetInstance() {
    //meyers singleton
    static InputManager instance;
    return instance;
}

int InputManager::GetMouseX() {
    return mouseX;
}

int InputManager::GetMouseY() {
    return mouseY;
}

bool InputManager::QuitRequested() {
    return quitRequested;
}

bool InputManager::KeyPress(int key)
{
    // Metodo que retorna se a tecla esta pressionada naquele instante (frame)
    if ((keyState[key] == true) && (keyUpdate[key] == updateCounter))
    {
        return true;
    }
    return false;
    
}

bool InputManager::KeyRelease(int key)
{
    // Metodo que retorna se a tecla esta solta naquele instante (frame)
    if ((keyState[key] == false) && (keyUpdate[key] == updateCounter))
    {
        return true;
    }
        return false;
}

bool InputManager::IsKeyDown(int key)
{
    // Metodo que retorna se a tecla esta pressionada independente de quando o evento inicial ocorreu
    if (keyState[key] == true)
    {
        return true;
    }

        return false;

}

bool InputManager::MousePress(int button)
{
    // Metodo que retorna se o bot�o do mouse esta pressionado naquele instante (frame)
    if ((mouseState[button] == true) && (mouseUpdate[button] == updateCounter))
    {
        return true;
    }

        return false;

}

bool InputManager::MouseRelease(int button)
{
    // Metodo que retorna se o bot�o do mouse esta solto naquele instante (frame)
    if ((mouseState[button] == false) && (mouseUpdate[button] == updateCounter))
    {
        return true;
    }

        return false;
 
}

bool InputManager::IsMouseDown(int button)
{
    
    if (mouseState[button] == true)
    {
        return true;
    }

        return false;

}