#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <TextureManager.hpp>
#include <GameObject.hpp>
#include <Player.hpp>
#include <Enemy.hpp>
#include <vector>
#include <InputHandler.hpp>
#include <GameStateMachine.hpp>
#include <PlayState.hpp>
#include <MenuState.hpp>

class Game{

	public:
		static Game* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new Game();
				return s_pInstance;
			}

			return s_pInstance;
		}


		bool init(const char *title, int xpos, int ypos, int width, int height,
		 		 bool fullscreen);	

		void render();
		void draw();
		void handleEvents();
		void update();
		void clean();
		void quit();
		SDL_Renderer *getRenderer() const {return m_pRenderer;}

	bool running(){ return is_running; }

	private:
		Game(){}
		static Game *s_pInstance;
		int m_currentState;
		GameStateMachine *m_pGameStateMachine;
		std::vector<GameObject*> m_gameObjects;
		SDL_Window *m_pWindow;
		SDL_Renderer *m_pRenderer;

		int m_currentFrame;
		bool is_running;
};

typedef Game TheGame;

#endif