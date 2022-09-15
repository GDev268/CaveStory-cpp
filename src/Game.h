#pragma once
#include <SDL.h>
#include "Player.h"
#include "Graphics.h"
#include "Level.h"


class Game{
public:
    Game(); //Constructor
    ~Game(); //Destructor
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    
    Player _player;
    Level _level;
};

