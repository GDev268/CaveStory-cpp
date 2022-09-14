#pragma once
#include <SDL.h>
#include <string>

#include "Graphics.h"

class Sprite
{
public:
    Sprite();
    Sprite(Graphics &graphics,const std::string &filePath,int sourceX,int sourceY,int width,int height,float posX,float posY);
    //needs to be virtual because of overriding issues
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics,int x,int y);
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
private:
    float _x,_y;
};
