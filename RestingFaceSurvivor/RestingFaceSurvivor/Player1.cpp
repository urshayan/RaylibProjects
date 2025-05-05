#include "Player1.h"
#include <iostream>



Player1::Player1(Texture2D tex, Vector2 pos) {
	texture1 = tex;
	position = pos;
	color1 = WHITE;
}
Player1::~Player1() {
	UnloadTexture(texture1);
}

void Player1::update() {
	// All the necessary Player Movements!
	// Checking For key Events 

	// Y movements
	if (IsKeyDown(KEY_UP)) {
		position.y -= 7;
	}
	if (IsKeyDown(KEY_DOWN)) {
		position.y += 7;
	}

	// X Movements
	if (IsKeyDown(KEY_LEFT)) {
		position.x -= 7;
	}
	if (IsKeyDown(KEY_RIGHT)) {
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

void Player1::Draw()const {
	DrawTextureV(texture1, position, color1);
	//std::cout << "X: " << position.x << " Y: " << position.y << std::endl;

}
Rectangle Player1::getRect() {
	return { position.x, position.y, (float)(texture1.width) - 3, (float)(texture1.height)-3};
}

void Player1::Reset()
{
	position = { 300 , 200 };
}



// escape Limits:
// X:  -1 839
// Y:  3 , 735