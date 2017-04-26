#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include <SDL2/SDL.h>
#include <Vector2D.hpp>
#include <vector>

enum mouse_buttons{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler{
	
	public:
		static InputHandler* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new InputHandler();
			}
			return s_pInstance;
		}
		void initialiseJoysticks();
		bool joysticksInitialised() {return m_bJoysticksInitialised;}
		void update();
		void clean();
		int xvalue(int joy, int stick);
		int yvalue(int joy, int stick);

		bool getButtonState(int joy, int buttonNumber){
			return m_buttonStates[joy][buttonNumber];
		}

		bool getMouseButtonState(int buttonNumber){
			return m_mouseButtonStates[buttonNumber];
		}

		Vector2D* getMousePosition(){
			return m_mousePosition;
		}

		bool isKeyDown(SDL_Scancode key);

	private:

		void onKeyDown();
		void onKeyUp();

		void onMouseMove(SDL_Event& event);
		void onMouseButtonDown(SDL_Event& event);
		void onMouseButtonUp(SDL_Event& event);
		
		void onJoystickAxisMove(SDL_Event& event);
		void onJoystickButtonDown(SDL_Event& event);
		void onJoystickButtonUp(SDL_Event& event);

		const int m_joystickDeadZone = 10000;
		Vector2D* m_mousePosition;
		std::vector<bool> m_mouseButtonStates;
		Uint8* m_keystates;
		std::vector<std::vector<bool>> m_buttonStates;
		std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
		std::vector<SDL_Joystick*> m_joysticks;
		bool m_bJoysticksInitialised;
		InputHandler() {
			for(int i = 0; i < 3; ++i)
				m_mouseButtonStates.push_back(false);
		}
		~InputHandler() {}
		static InputHandler *s_pInstance;

};

typedef InputHandler TheInputHandler;

#endif