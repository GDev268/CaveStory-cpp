#pragma once
#include "Graphics.h"
#include "AnimatedSprite.h"

class Player : public AnimatedSprite {
public:
    Player();
    Player(Graphics &graphics,float x,float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    void moveLeft();
    void moveRight();
    void stopMoving();

    virtual void animationEnd(std::string currentAnimation);
    virtual void setupAnimations();
private:
    float _dx, _dy;

    Direction _facing;
};