#include "../include/Camera.h"
#include "../include/InputManager.h"
const int GAME_WIDTH = 1024;
const int GAME_HEIGHT = 600;

#define SPEED 200
GameObject* Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

void Camera::Follow(GameObject* newFocus) {
	focus = newFocus;
}

void Camera::Unfollow() {
	focus = nullptr;
}

void Camera::Update(float dt) {
	if (focus != nullptr) {
		pos.x = focus->box.x + focus->box.w - GAME_WIDTH / 2;
		pos.y = focus->box.y + focus->box.h - GAME_HEIGHT / 2;
	}
	else {
		InputManager& input = InputManager::GetInstance();

		if (input.IsKeyDown(RIGHT_ARROW_KEY)) {
			speed.x = SPEED;
		}
		else if (input.IsKeyDown(LEFT_ARROW_KEY)) {
			speed.x = -SPEED;
		}
		else {
			speed.x = 0;
		}

		if (input.IsKeyDown(UP_ARROW_KEY)) {
			speed.y = -SPEED;
		}
		else if (input.IsKeyDown(DOWN_ARROW_KEY)) {
			speed.y = SPEED;
		}
		else {
			speed.y = 0;
		}

		pos.x += speed.x * dt;
		pos.y += speed.y * dt;
	}
}