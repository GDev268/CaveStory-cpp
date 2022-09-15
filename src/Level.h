#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "Global.h"

class Level {
public:
    Level();
    Level(const std::string mapName,Vector2 spawnPoint,Graphics &graphics);
    ~Level();
    void update(int elapsedTime);
    void draw(Graphics &graphics);
private:
    std::string _mapName;
    Vector2 _spawnPoint;
    Vector2 _size;
    SDL_Texture* _backgroundTexture;

    void loadMap(std::string mapName, Graphics &graphics);
};