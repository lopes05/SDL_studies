#include <Game.hpp>

bool Game::init(const char *title, int xpos, int ypos, int width, int height,
				bool fullscreen){

	int flags = 0;
	IMG_Init(IMG_INIT_PNG);
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
				SDL_SetRenderDrawColor(m_pRenderer, 255,255,255,255);
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
	is_running = true;
	SDL_Surface* pTempSurface = IMG_Load("assets/never.png");

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRect.w, 
		&m_sourceRect.h);

	m_destinationRect.x = m_sourceRect.x = 0;
	m_destinationRect.y = m_sourceRect.y = 0;
	m_destinationRect.w = m_sourceRect.w;
	m_destinationRect.w = m_sourceRect.h;

	return true;
}


void Game::render(){
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRect, &m_destinationRect);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update(){

}

void Game::clean(){
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
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

