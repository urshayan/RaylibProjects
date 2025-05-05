#pragma once
#include <raylib.h>
class Player2
{
public:
	Player2(Texture2D tex, Vector2 pos);
	~Player2();
	void update();
	void Draw()const;
	Rectangle getRect();
	Vector2 position;
	void Reset();
private:
	Texture2D texture2;
	
	Color color2;
};

