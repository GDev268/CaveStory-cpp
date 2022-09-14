
#include <map>
#include <string>
#include <vector>

#include "Sprite.h"
#include "Graphics.h"
#include "Global.h"

class Animation : public Sprite {
public:
    Animation();
    Animation(Graphics& graphics, const std::string &filePath, int sourceX, int sourceY,int width, int height, float posX,float posY,float timeToUpdate);
    ~Animation();

    //Plays the animation
    void playAnimation(std::string animation,bool once = false);

    //Updates the animations of the sprite
    void update(int elapsedTime);

    //Draws the sprite on the screen
    void draw(Graphics &graphics, int x,int y);

    //Sets all the animations
    virtual void setupAnimations();

protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    //Adds the animation
    void addAnimation(int frames,int x,int y,std::string name,int width,int height, Vector2 offset);
    
    //Reset all the animations
    void resetAnimations();

    //Stops the Animation
    void stopAnimation();

    //Change the visibility of the sprite
    void setVisible(bool visible);

    //Triggers when a animation ends
    virtual void animationEnd(std::string currentAnimation);
private:
    std::map<std::string,std::vector<SDL_Rect>> animations;
    std::map<std::string,Vector2> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};