#include "../include/Face.h"

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
void Face::Update(float dt) {}

void Face::Render() {}


bool Face::Is(string type) {
	return type == "Face";
}
