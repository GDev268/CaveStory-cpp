//Gonna redo all the text class later :/
#include <string>
#include <iostream>
#include <map>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Text.h"
#include "Graphics.h"

Text::Text() {}

Text::Text(SDL_Renderer* renderer,std::string pathFont,int textSize,SDL_Color color,std::string text,float posX,float posY){
    _text = text;
    textFont = TTF_OpenFont(pathFont.c_str(),textSize);
    textRect = new SDL_Rect();
    textColor = color;
    _pathFont = pathFont;
    _textSize = textSize;

    textRect->x = posX;
    textRect->y = posY;

    textSurface = TTF_RenderText_Solid(textFont,_text.c_str(), textColor);
    if(textSurface == nullptr){
        printf("ERROR: Failed to create textSurface");
    }

    textTexture = SDL_CreateTextureFromSurface(renderer,textSurface);
    if(textTexture == nullptr){
        printf("ERROR: Failed to create textTexture");
    } 

    TTF_CloseFont(textFont);
    SDL_FreeSurface(textSurface);
}

Text::~Text() {}

void Text::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, textTexture, NULL, textRect);
}

void Text::update(SDL_Renderer* renderer) {
    textFont = TTF_OpenFont(_pathFont.c_str(),_textSize);
    textSurface = TTF_RenderText_Solid(textFont,_text.c_str(), textColor);

    SDL_DestroyTexture(textTexture);
    textTexture = SDL_CreateTextureFromSurface(renderer,textSurface);
    
}

void Text::SetText(std::string text, SDL_Renderer* renderer)
{
    _text = text;
    update(renderer);
}


