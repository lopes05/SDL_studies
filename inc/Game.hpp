#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <TextureManager.hpp>

class Game{

	public:
		Game(){}
		~Game(){}

		bool init(const char *title, int xpos, int ypos, int width, int height,
		 		 bool fullscreen);	

		void render();
		void handleEvents();
		void update();
		void clean();

	bool running(){ return is_running; }

	private:
		SDL_Window *m_pWindow;
		SDL_Renderer *m_pRenderer;

		int m_currentFrame;
		bool is_running;
};

#endif