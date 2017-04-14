#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

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

		SDL_Texture *m_pTexture;
		SDL_Rect m_sourceRect;
		SDL_Rect m_destinationRect;

		bool is_running;
};

#endif