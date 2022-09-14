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
    Text();
    Text(Graphics &graphics,int x,int y,int size,const std::string &text,const std::string &font,Color color,double alpha);
    virtual ~Text();

    void Create(Graphics &graphics);
    void SetText(std::string text);
    void setFont(std::string font);
    void draw(Graphics &graphics);
    //void SetAlpha(int alpha);
    void destroy();

    int _x;
    int _y;
    int srcw;
    int srch;
    int _size;
    int _alpha;
    Color _color;
    std::string _font;
    std::string _text;
    Graphics _graphics;
    SDL_Texture* _texture;
};