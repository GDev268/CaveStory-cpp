#include "Tile.h"
#include "Graphics.h"

#include <SDL.h>

Tile::Tile() {}

Tile::Tile(SDL_Texture* tileset, Vector2 tilePos, Vector2 tileSize,Vector2 position):
    _tileset(tileset),
    _tilePos(tilePos),
    _tileSize(tileSize),
    _position(position.x * Global::PLAYER_SIZE,position.y * Global::PLAYER_SIZE)
{}

void Tile::update(int elapsedTime) {}

void Tile::draw(Graphics &graphics) {
    SDL_Rect dstRect = {this->_position.x, this->_position.y, this->_tileSize.x * Global::PLAYER_SIZE, this->_tileSize.x * Global::PLAYER_SIZE};
    SDL_Rect srcRect = {this->_tilePos.x,this->_tilePos.y, this->_tileSize.x * Global::PLAYER_SIZE, this->_tileSize.x * Global::PLAYER_SIZE};
    graphics.blitSurface(_tileset, &srcRect, &dstRect);
}