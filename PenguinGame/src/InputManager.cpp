#include "../include/InputManager.h"

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
void InputManager::Update()
{
    
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