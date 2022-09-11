
#include <SDL2/SDL.h>
#include <SDL_image.h>

#include "Window.h"

Window::Window() {
	SDL_CreateWindowAndRenderer(640,480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cavestory");
}

Window::~Window() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}