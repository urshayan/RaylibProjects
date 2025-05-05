#pragma once
#include <raylib.h>
class Player1
{
public:
	Player1(Texture2D tex , Vector2 pos);
	~Player1();
	void update();
	void Draw()const;
	Rectangle getRect();
	Vector2 position;
	void Reset();


private:
	Texture2D texture1;

	Color color1;
};

