#include <SDL2/SDL.h>
#include <SDL_image.h>

#include "Graphics.h"
#include "Global.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(Global::SCREEN_WIDTH,Global::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

//Loads the desired image
SDL_Surface* Graphics::loadImage(const std::string &filePath){
	//Check if the image exists on the spritesheet hasmap
	if(this->_spriteSheet.count(filePath) == 0){
		this->_spriteSheet[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheet[filePath];
}

void Graphics::blitSurface(SDL_Texture* source,SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle){
	//Copies the texture selected to the rendering target
	SDL_RenderCopy(this->_renderer,source,sourceRectangle,destinationRectangle);
}


void Graphics::flip(){
	//Updates the screen for the sprites to appear
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear(){
	//Clears all renders on the screen
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
	//Gets the renderer
	return this->_renderer;
}