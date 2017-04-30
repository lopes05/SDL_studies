#include <MenuButton.hpp>
#include <InputHandler.hpp>
#include <iostream>

MenuButton::MenuButton(const LoaderParams* pParams) : SDLGameObject(pParams){
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw(){
	SDLGameObject::draw();
}

void MenuButton::update(){
	Vector2D *pMousepos = TheInputHandler::Instance()->getMousePosition();
	
	if(pMousepos->getX() < (m_position.getX()+m_width)
		&& pMousepos->getX() > m_position.getX()
		&& pMousepos->getY() < (m_position.getY() + m_height)
		&& pMousepos->getY() > m_position.getY()){
		m_currentFrame = MOUSE_OVER;

		if(TheInputHandler::Instance()->getMouseButtonState(LEFT)){
			m_currentFrame = CLICKED;
		}
	}
	else{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean(){
	SDLGameObject::clean();
}