#include <InputHandler.hpp>
#include <Game.hpp>
#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler(){
	for(int i = 0; i < 3; ++i)
		m_mouseButtonStates.push_back(false);
}

void InputHandler::initialiseJoysticks(){
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0){
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if(SDL_NumJoysticks() > 0){
		for(int i = 0; i < SDL_NumJoysticks(); ++i){
			SDL_Joystick *joy = SDL_JoystickOpen(i);
			if(joy){
				m_joysticks.push_back(joy);
				m_joystickValues.push_back(std::make_pair(
					new Vector2D(0, 0), new Vector2D(0, 0)));

				std::vector<bool> tempButtons;

				for(int j = 0; j < SDL_JoystickNumButtons(joy); ++j){
					tempButtons.push_back(false);
				}

				m_buttonStates.push_back(tempButtons);
			}
			else{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;
	}
	else{

		m_bJoysticksInitialised = false;
	}

	std::cout << "Initialised " << m_joysticks.size() << " joystick(s)\n";
}

void InputHandler::clean(){
	if(m_bJoysticksInitialised){
		for(int i = 0; i < SDL_NumJoysticks(); ++i){
			SDL_JoystickClose(m_joysticks[i]);
		}
	}

	std::cout << "cleaned all joysticks\n";
}

void InputHandler::update(){
	SDL_Event event;
	m_keystates = SDL_GetKeyboardState(0);
	while(SDL_PollEvent(&event)){
		
		switch(event.type){
			case SDL_QUIT:
				TheGame::Instance()->quit();
				break;

			case SDL_JOYAXISMOTION:
				onJoystickAxisMove(event);
				break;

			case SDL_JOYBUTTONDOWN:
				onJoystickButtonDown(event);
				break;

			case SDL_JOYBUTTONUP:
				onJoystickButtonUp(event);
				break;

			case SDL_MOUSEMOTION:
				onMouseMove(event);
				break;

			case SDL_MOUSEBUTTONDOWN:

			case SDL_MOUSEBUTTONUP:
				onMouseButtonUpDown(event);
			break;

			case SDL_KEYDOWN:
				onKeyDown();
				break;

			case SDL_KEYUP:
				onKeyUp();
				break;

			default:
				break;
		}
	}
}

int InputHandler::xvalue(int joy, int stick){
	if(m_joystickValues.size() > 0){
		if(stick == 1){
			return m_joystickValues[joy].first->getX();
		}
		else if(stick == 2){
			return m_joystickValues[joy].second->getX();
		}
	}

	return 0;
}

int InputHandler::yvalue(int joy, int stick){
	if(m_joystickValues.size() > 0){
		if(stick == 1){
			return m_joystickValues[joy].first->getY();
		}
		else if(stick == 2){
			return m_joystickValues[joy].second->getY();
		}
	}

	return 0;
}

void InputHandler::onKeyDown(){
}

void InputHandler::onKeyUp(){
}

bool InputHandler::isKeyDown(SDL_Scancode key){
			if(m_keystates){
				return m_keystates[key] == 1;
			}
			return false;
}

void InputHandler::onMouseButtonUpDown(SDL_Event& event){
	int buttonTypes[] {SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT};

	for(int i=0; i<3; i++){
		if(event.button.button == buttonTypes[i]){
			m_mouseButtonStates[i] = event.type == SDL_MOUSEBUTTONDOWN;
		}
	}
}

void InputHandler::onMouseMove(SDL_Event& event){
	if(event.type == SDL_MOUSEMOTION){
		m_mousePosition.setX(event.motion.x);
		m_mousePosition.setY(event.motion.y);
	}
}

void InputHandler::onJoystickAxisMove(SDL_Event& event){
	int whichOne = event.jaxis.which;

	if(event.jaxis.axis == 0){
		if(event.jaxis.value > m_joystickDeadZone){
			m_joystickValues[whichOne].first->setX(1);
		}
		else if(event.jaxis.value < -m_joystickDeadZone){
			m_joystickValues[whichOne].first->setX(-1);
		}
		else{
			m_joystickValues[whichOne].first->setX(0);
		}
	}

	if(event.jaxis.axis == 1){
		if(event.jaxis.value > m_joystickDeadZone){
			m_joystickValues[whichOne].first->setY(1);
		}
		else if(event.jaxis.value < -m_joystickDeadZone){
			m_joystickValues[whichOne].first->setY(-1);
		}
		else{
			m_joystickValues[whichOne].first->setY(0);
		}
	}

	if(event.jaxis.axis == 3){
		if(event.jaxis.value > m_joystickDeadZone){
			m_joystickValues[whichOne].second->setX(1);
		}
		else if(event.jaxis.value < -m_joystickDeadZone){
			m_joystickValues[whichOne].second->setX(-1);
		}
		else{
			m_joystickValues[whichOne].second->setY(0);
		}
	}

	if(event.jaxis.axis == 4){
		if(event.jaxis.value > m_joystickDeadZone){
			m_joystickValues[whichOne].second->setY(1);
		}
		else if(event.jaxis.value < -m_joystickDeadZone){
			m_joystickValues[whichOne].second->setY(-1);
		}
		else{
			m_joystickValues[whichOne].second->setY(0);
		}
	}
}

void InputHandler::onJoystickButtonDown(SDL_Event& event){
	int whichOne = event.jaxis.which;
	m_buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event& event){
	int whichOne = event.jaxis.which;
	m_buttonStates[whichOne][event.jbutton.button] = false;
}

void InputHandler::reset(){
	
}