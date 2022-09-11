#include <SDL.h>
#include <string>

class Window {
public:
	Window();
	~Window();
private:

    SDL_Window* _window;
    SDL_Renderer* _renderer;
};