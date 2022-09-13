#include <SDL.h>
#include "Sprite.h"
#include "Graphics.h"

class Game{
public:
    Game(); //Constructor
    ~Game(); //Destructor
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    
    Sprite _player;
};

