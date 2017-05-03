#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include <TextureManager.hpp>
#include <GameObject.hpp>
#include <InputHandler.hpp>

#include <GameObjectFactory.hpp>

#include <AnimatedGraphicCreator.hpp>
#include <MenuButtonCreator.hpp>
#include <PlayerCreator.hpp>
#include <EnemyCreator.hpp>

#include <GameStateMachine.hpp>
#include <PlayState.hpp>
#include <MainMenuState.hpp>
#include <PauseState.hpp>
#include <GameOverState.hpp>

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
		GameStateMachine *getStateMachine(){return m_pGameStateMachine;}
		int getGameWidth() const { return m_gameWidth; }
		int getGameHeight() const { return m_gameHeight; }

		bool running(){ return is_running; }

	private:
		Game(){}
		static Game *s_pInstance;
		int m_currentState;
		
		std::vector<GameObject*> m_gameObjects;
		SDL_Window *m_pWindow;
		SDL_Renderer *m_pRenderer;

		GameObject* m_go;
		GameObject* m_player;
		GameObject* m_enemy;

		int m_gameWidth;
		int m_gameHeight;
		
		int m_currentFrame;
		bool is_running;

		GameStateMachine *m_pGameStateMachine;
};

typedef Game TheGame;

#endif