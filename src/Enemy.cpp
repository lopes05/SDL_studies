#include <Enemy.hpp>

Enemy::Enemy(const LoaderParams *pParams) : SDLGameObject(pParams){

}

void Enemy::update(){
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}


void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::clean(){

}
