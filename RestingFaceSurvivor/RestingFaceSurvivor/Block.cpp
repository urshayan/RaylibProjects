#include "Block.h"



Block::Block(Vector2 pos, Vector2 size, Color col) {
    position = pos;
    dimensions = size;
    color = col;
}

void Block::Draw() const {
    DrawRectangleV(position, dimensions, color);
}

Rectangle Block::GetRect() const{
    return { position.x, position.y, dimensions.x -2, dimensions.y - 2 };
}
