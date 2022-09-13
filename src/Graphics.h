#pragma once
#include <SDL.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

    //Loads the image to the _spriteSheet map (cache) but don't load on the screen
    SDL_Surface* loadImage(const std::string &filePath);

    //Draws the texture 
    void blitSurface(SDL_Texture* source,SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    //Renders everything to the screen
    void flip();

    //Clears the screen
    void clear();
    
    //Returns the render
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string,SDL_Surface*> _spriteSheet;
};