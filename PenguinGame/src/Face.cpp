#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"

Face::Face(GameObject& associated) : Component(associated) {
	/*
Primeiro, deve construir sua classe mãe e depois setar o valor inicial
de hitpoints. (sugestão: 30 HP)
*/
	hitpoints = 30;
}

void Face::Damage(int damage) {
/*
Deve reduzir os hitpoints na quantidade passada. E se ficar menor
ou igual a zero, chame o RequestDelete do GO que o contém (associated),
e dê play no componente Sound de seu associated, se houver um.
*/
	hitpoints -= damage;
	if (hitpoints <= 0)
		associated.RequestDelete();

}
void Face::Update(float dt) {
	InputManager& input = InputManager::GetInstance();

	if (input.MousePress(LEFT_MOUSE_BUTTON)) {
		if (associated.box.Contains(input.GetMouseX() + Camera::pos.x, input.GetMouseY() + Camera::pos.y)) {
			cout << "Damage applied.";
			Damage(std::rand() % 10 + 10);
		}
	}
}

void Face::Render() {}


bool Face::Is(string type) {
	return type == "Face";
}
