#include "Sprite.h"
#include "Graphics.h"
#include "Global.h"

Sprite::Sprite(){}

Sprite::Sprite(Graphics &graphics,const std::string &filePath,int sourceX,int sourceY,int width,int height,float posX,float posY):
_x(posX),
_y(posY)
{
    //Saves the basic sprite attributes
    this->_sourceRect.x = sourceX;
    this->_sourceRect.y = sourceY;
    this->_sourceRect.w = width;
    this->_sourceRect.h = height;

    //Creates the sprite and saves in the _spriteSheet hashmap
    //WARNING: This function is declaring the graphics variable NOT THE CLASS if the class is declared the game doesn't compile
    this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if(this->_spriteSheet == NULL){
        printf("\nError: Couldn't load the image!\n");
    }
}

Sprite::~Sprite(){}

void Sprite::draw(Graphics &graphics,int x,int y){
    //Creates the destination of the sprites
    SDL_Rect destinationRectangle = { x,y,this->_sourceRect.w * Global::PLAYER_SIZE,this->_sourceRect.h * Global::PLAYER_SIZE};

    //Loads the sprite
    //WARNING: This function is declaring the graphics variable NOT THE CLASS if the class is declared the game doesn't compile
    graphics.blitSurface(this->_spriteSheet,&this->_sourceRect,&destinationRectangle);

}

void Sprite::update(){}