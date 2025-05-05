#include "Player2.h"
#include <raylib.h>



Player2::Player2(Texture2D tex, Vector2 pos) {
	texture2 = tex;
	position = pos;
	color2 = WHITE;
}
Player2::~Player2() {
	UnloadTexture(texture2);
}

void Player2::update() {
	// All the necessary Player Movements!
	// Checking For key Events 

	// Y movements
	if (IsKeyDown(KEY_W)) {
		position.y -= 7;
	}
	if (IsKeyDown(KEY_S)) {
		position.y += 7;
	}

	// X Movements
	if (IsKeyDown(KEY_A)) {
		position.x -= 7;
	}
	if (IsKeyDown(KEY_D)) {
		position.x += 7;
	}
	// Adding Logics for X and Y escape Values!
	if (position.x <= -1) {
		position.x = -1;
	}
	if (position.x >= 835) {
		position.x = 835;
	}
	if (position.y <= 3) {
		position.y = 3;
	}
	if (position.y >= 735) {
		position.y = 735;
	}
}

void Player2::Draw()const {
	DrawTextureEx(texture2, position, 0.0f, 0.6f, color2);
}
Rectangle Player2::getRect() {
	return { position.x, position.y, float(texture2.width)-20, float(texture2.height-20) };
}

void Player2::Reset()
{
	position = { 520 , 550 };
}
