#include <Player.hpp>
#include <InputHandler.hpp>

Player::Player() : SDLGameObject(){

}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update(){
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	
	handleInput();
	SDLGameObject::update();
}

void Player::clean(){

}

void Player::handleInput(){
	if(TheInputHandler::Instance()->joysticksInitialised()){
		int t_x = TheInputHandler::Instance()->xvalue(0, 1);
		int t_y = TheInputHandler::Instance()->yvalue(0, 1);
		
		Vector2D velocity(t_x, t_y);
		velocity = velocity.normalize();

		int boost = 1;

		if(TheInputHandler::Instance()->getButtonState(0, 0)){
			boost = 3;
		}

		m_velocity.setX(boost * velocity.getX());
		m_velocity.setY(boost * velocity.getY());
	}

	Vector2D target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = target - m_position;
	m_velocity /= 50;


}

void Player::load(const LoaderParams *pParams){
	SDLGameObject::load(pParams);
}