#pragma once
#include <SDL.h>
#include <vector>
#include <SDL_image.h>

#include "Tile.h"
#include "Graphics.h"
#include "Global.h"

struct Tileset;

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
    Vector2 _tileSize;
    SDL_Texture* _backgroundTexture;

    std::vector<Tile> _tileList;
    std::vector<Tileset> _tilesets;

    void loadMap(std::string mapName, Graphics &graphics);
};

//Tileset Structure
struct Tileset {
    SDL_Texture* _texture;
    int _firstGid;

    Tileset() {
        this->_firstGid = -1;
    }

    Tileset(SDL_Texture* texture, int firstGid){
        this->_texture = texture;
        this->_firstGid = firstGid;
    }
};