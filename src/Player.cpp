#include "Player.h"
#include "Graphics.h"

namespace PlayerConstants {
    const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics &graphics,float x,float y):
    AnimatedSprite(graphics,"assets/images/MyChar.png",0,0,16,16,x,y,-500.1)
{
    graphics.loadImage("assets/images/MyChar.png");
    this->setupAnimations();
    this->playAnimation("RUNNING_RIGHT");
}

void Player::setupAnimations() {
    this->addAnimation(3,0,0,"RUNNING_LEFT",16,16,Vector2(0,0));
    this->addAnimation(3,0,16,"RUNNING_RIGHT",16,16,Vector2(0,0));
    this->addAnimation(1,0,0,"IDLE_LEFT",16,16,Vector2(0,0));
    this->addAnimation(1,0,16,"IDLE_RIGHT",16,16,Vector2(0,0));
}

void Player::animationEnd(std::string currentAnimation) {}

void Player::moveLeft(){
    this->_dx = -PlayerConstants::WALK_SPEED;
    this->playAnimation("RUNNING_LEFT");
    this->_facing = LEFT;
}

void Player::moveRight(){
    this->_dx = PlayerConstants::WALK_SPEED;
    this->playAnimation("RUNNING_RIGHT");
    this->_facing = RIGHT;
}

void Player::stopMoving(){
    this->_dx = 0.0f;
    this->playAnimation(_facing == RIGHT ? "IDLE_RIGHT" : "IDLE_LEFT");
}

void Player::update(float elapsedTime) {
    
    //Change x value
    this->_x += _dx * elapsedTime;

    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics){
   AnimatedSprite::draw(graphics, this->_x, this->_y);
}