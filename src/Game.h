#include <SDL.h>

class Graphics;

class Game{
public:
    Game(); //Constructor
    ~Game(); //Destructor
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
};

