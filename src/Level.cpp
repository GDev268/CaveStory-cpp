#include "Level.h"
#include "Graphics.h"

#include <SDL2/SDL.h>

Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
		_mapName(mapName),
		_spawnPoint(spawnPoint),
		_size(Vector2(0,0))
{
	this->loadMap(mapName, graphics);
}

Level::~Level() {

}

void Level::loadMap(std::string mapName, Graphics &graphics) {
	this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
			graphics.loadImage("assets/images/backgrounds/bkBlue.png"));
	this->_size = Vector2(1280, 960);
}

void Level::update(int elapsedTime) {

}

void Level::draw(Graphics &graphics) {
	//Draw the background
	SDL_Rect sourceRect = { 0, 0, 64, 64 };
	SDL_Rect destRect;
	for (int x = 0; x < this->_size.x / 64; x++) {
		for (int y = 0; y < this->_size.y / 64; y++) {
			destRect.x = x * 64 * Global::PLAYER_SIZE;
			destRect.y = y * 64 * Global::PLAYER_SIZE;;
			destRect.w = 64 * Global::PLAYER_SIZE;;
			destRect.h = 64 * Global::PLAYER_SIZE;;
			graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);
		}
	}
}