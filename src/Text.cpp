#include <cmath>
#include <SDL_ttf.h>

#include "Text.h"
#include "Graphics.h"

Text::Text() {}

Text::Text(Graphics &graphics,int x,int y,int size,const std::string &text,const std::string &font,Color color,double alpha):
_x(x),
_y(y)
{
    this->_size = size;
    this->_text = text;
    this->_font = font.c_str();
    this->_color = {color.r,color.g,color.b};
    this->_alpha = 255 * alpha;
    this->_graphics = graphics;

    Create(_graphics);
}

Text::~Text() {}

void Text::Create(Graphics &graphics){
    const char* text = _text.c_str();
    SDL_Renderer* renderer = graphics.getRenderer();
    TTF_Font* font = TTF_OpenFont(("./assets/fonts/" + _font + ".ttf").c_str(), _size);
    SDL_Color color = {_color.r,_color.g,_color.b,_alpha};
    if(font == nullptr){
        printf("ERROR: Unable to open font");
        exit(1);
    }

    SDL_Surface* surface = TTF_RenderText_Blended(font,text,color);
    if(surface == nullptr){
        printf("ERROR: Unable to create surface");
        exit(1);
    }

    if(surface != nullptr && _texture != nullptr){
        SDL_DestroyTexture(_texture);
    }

    _texture = SDL_CreateTextureFromSurface(renderer,surface);
    if(surface == nullptr){
        printf("ERROR: Unable to create texture");
        exit(1);
    }

    SDL_FreeSurface(surface);
}

void Text::draw(Graphics &graphics){

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 1;
    srcRect.h = 1;
    
    srcRect.x = _x;
    srcRect.y = _y + _size;
    srcRect.w += (_size * _text.length());
    srcRect.h += _size;

    graphics.blitSurface(this->_texture,&srcRect,&destRect);

    SDL_DestroyTexture(_texture);
}