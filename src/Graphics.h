#include <SDL.h>
#include <string>

class Graphics {
public:
	Graphics();
	~Graphics();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};