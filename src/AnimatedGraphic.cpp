#include <AnimatedGraphic.hpp>

AnimatedGraphic::AnimatedGraphic() : SDLGameObject(){

}

void AnimatedGraphic::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}


void AnimatedGraphic::update(){
	m_currentFrame = int (((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
	SDLGameObject::update();
}

void AnimatedGraphic::clean(){
	SDLGameObject::clean();
}

void AnimatedGraphic::draw(){
	SDLGameObject::draw();
}