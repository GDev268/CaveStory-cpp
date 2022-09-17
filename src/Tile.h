#pragma once
#include "Graphics.h"
#include "Global.h"

struct SDL_Texture;

class Tile{
public:
    Tile();
    Tile(SDL_Texture* tileset, Vector2 tilePos, Vector2 tileSize,Vector2 position);
    void update(int elapsedTime);
    void draw(Graphics &graphics);
private:
    SDL_Texture* _tileset;
    Vector2 _tilePos;
    Vector2 _tileSize;
    Vector2 _position;
};