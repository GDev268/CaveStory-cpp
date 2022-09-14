
#include "Animation.h"
#include "Graphics.h"

Animation::Animation() {}

Animation::Animation(Graphics& graphics, const std::string &filePath, int sourceX, int sourceY,int width, int height, float posX,float posY,float timeToUpdate):
    Sprite(graphics,filePath,sourceX,sourceY,width,height,posX,posY),
    _frameIndex(0),
    _timeToUpdate(_timeToUpdate),
    _visible(true),
    _currentAnimationOnce(false),
    _currentAnimation("")
{

}

Animation::~Animation() {}

void Animation::addAnimation(int frames,int x,int y,std::string name,int width,int height, Vector2 offset) {
    std::vector<SDL_Rect> rectangles;
    for(int i=0; i < frames; i++) {
        SDL_Rect newRect = {(i + x) * width,y,width,height};
        rectangles.push_back(newRect);
    }

    this->animations.insert(std::pair<std::string,std::vector<SDL_Rect>>(name,rectangles));
    this->_offsets.insert(std::pair<std::string,Vector2>(name,offset));
}

void Animation::resetAnimations() {
    this->animations.clear();
    this->_offsets.clear();
}

void Animation::playAnimation(std::string animation,bool once) {
    this->_currentAnimationOnce = once;
    
    //If the current animation is incorrect to the string start change the animation and start from the frame zero
    if(this->_currentAnimation != animation) {
        this->_currentAnimation = animation;
        this->_frameIndex = 0;
    }
}

void Animation::setVisible(bool visible) {
    this->_visible = visible;
}

void Animation::stopAnimation() {
    this->_frameIndex = 0;
    animationEnd(this->_currentAnimation);
}

void Animation::update(int elapsedTime) {
    Sprite::update();

    this->_timeElapsed = elapsedTime;
    if(this->_timeElapsed > this->_timeToUpdate) {
        if(this->_frameIndex < animations[this->_currentAnimation].size() - 1) {
            _frameIndex++;
        }
        else{
            if(_currentAnimationOnce){
                this->setVisible(false);
            }
            this->_frameIndex = 0;
            this->animationEnd(this->_currentAnimation);
        }
    }
}

void Animation::draw(Graphics &graphics, int x,int y){
    if(_visible){
        SDL_Rect destRect;
        destRect.x = x + _offsets[this->_currentAnimation].x;
        destRect.y = y + _offsets[this->_currentAnimation].y;
        destRect.w = this->_sourceRect.w * Global::PLAYER_SIZE;
        destRect.h = this->_sourceRect.h * Global::PLAYER_SIZE;

        SDL_Rect sourceRect = this->animations[this->_currentAnimation][this->_frameIndex];
        graphics.blitSurface(this->_spriteSheet,&sourceRect,&destRect);
    }
}

void Animation::animationEnd(std::string currentAnimation){

}

void Animation::setupAnimations() {
    this->addAnimation(3,0,0,"RUNNING_LEFT",16,16,Vector2(0,0));
}