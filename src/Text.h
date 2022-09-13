#include <string>
#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Sprite.h"
#include "Graphics.h"

struct Color {
    int r;
    int g;
    int b;
};

class Text{
public:
    Text(Graphics* graphics,int x,int y,int size,std::string text,std::string font,Color color);
    virtual ~Text();

    void Create();
    void SetText(std::string text);
    void setFont(std::string font);
    void SetAlpha(int alpha);
    void destroy();
private:
    SDL_Rect* srcRect;
    SDL_Rect* dstRect;
    Graphics* _graphics;
    int _x;
    int _y;
    int _size;
    std::string _text;
    TTF_Font* _font;
    SDL_Color _color;
    SDL_Surface* _surface;
    SDL_Texture* _texture;
};