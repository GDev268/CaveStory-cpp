#include "Text.h"
#include "Graphics.h"

Text::Text(Graphics* graphics,int x,int y,int size,std::string text,std::string font,Color color){
    this->_graphics = graphics;
    this->_x = x;
    this->_y = y;
    this->_size = size;
    this->_text = text;
    this->_color = {color.r,color.g,color.b};
    
    setFont(font);
};



void Text::setFont(std::string font){
    _font = TTF_OpenFont(("assets/fonts/" + font + ".ttf").c_str(),_size);
}