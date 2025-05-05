#pragma once
#include <raylib.h>

class Block {
public:
    Block(Vector2 pos, Vector2 size, Color col);

    void Draw() const;
    Rectangle GetRect()const ;

private:
    Vector2 position;
    Vector2 dimensions;
    Color color;
};
