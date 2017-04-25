#include <Player.hpp>

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){

}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update(){
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_x -= 1;
}

void Player::clean(){

}