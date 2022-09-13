#include <string>
#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Sprite.h"

//Gonna redo all the text class later :/
class Text{
public:
    Text();
    Text(SDL_Renderer* renderer,std::string pathFont,int textSize,SDL_Color color,std::string text,float posX,float posY);
    virtual ~Text();

    void render(SDL_Renderer* renderer);
    void update(SDL_Renderer* renderer);
    void SetText(std::string text, SDL_Renderer* renderer);

private:

    SDL_Rect* textRect = nullptr;
    SDL_Surface* textSurface = nullptr;
    SDL_Texture* textTexture = nullptr;
    SDL_Color textColor;
    TTF_Font* textFont;
    std::string _pathFont;
    int _textSize;

    std::string _text;
};