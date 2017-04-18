#include <Game.hpp>

bool Game::init(const char *title, int xpos, int ypos, int width, int height,
				bool fullscreen){

	int flags = 0;
	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "Jogo iniciado com sucesso\n";

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if(m_pWindow){
			std::cout << "Tela iniciada com sucesso\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if(m_pRenderer){
				std::cout << "Criação do renderer OK\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255 , 0, 0, 255);
			}
			else{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else{
			std::cout << "window init fail\n";
			return false;
		}
	}
	else{
		std::cout << "SDL init fail\n";
		return false; 
	}

	std::cout << "Init OK!\n";
	

	if(!TheTextureManager::Instance()->load("assets/cat.png", "animate", m_pRenderer))
		return false;

	is_running = true;

	return true;
}


void Game::render(){
	SDL_RenderClear(m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update(){
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::clean(){
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	IMG_Quit();
	SDL_Quit();
}

void Game::handleEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				is_running = false;
			break;

			default:
			break;
		}
	}
}

