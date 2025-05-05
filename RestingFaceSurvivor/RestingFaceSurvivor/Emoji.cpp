#include "Emoji.h"
Emoji::Emoji(float x, float y, float speed, Texture2D& texture) {

}



void Emoji::Update(float time) {
	position.y += fallSpeed * time;
}

void Emoji::Draw()const {
	DrawTextureV(*texture, position, WHITE;
}
bool Emoji::IsOffScreen()const {
	return position.y > GetScreenHeight();
}

Rectangle Emoji::GetRect()const {
	return { position.x , position.y , (float)texture->width ,(float)texture->height };
}

