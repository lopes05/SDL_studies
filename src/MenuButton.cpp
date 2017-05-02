#include <MenuButton.hpp>
#include <InputHandler.hpp>
#include <iostream>

MenuButton::MenuButton() : SDLGameObject(){
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw(){
	SDLGameObject::draw();
}

void MenuButton::update(){
	Vector2D pMousepos = TheInputHandler::Instance()->getMousePosition();
	
	if(pMousepos.getX() < (m_position.getX()+m_width)
		and pMousepos.getX() > m_position.getX()
		and pMousepos.getY() < (m_position.getY() + m_height)
		and pMousepos.getY() > m_position.getY()){
		m_currentFrame = MOUSE_OVER;
		if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased){
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}
		else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)){
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
	m_callbackID = pParams -> getCallbackID();
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::clean(){
	SDLGameObject::clean();
}