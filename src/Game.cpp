#include <Game.hpp>

Game* Game::s_pInstance = 0;

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
	TheInputHandler::Instance()->initialiseJoysticks();
	std::cout << "Init OK!\n";

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());
	
	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());

	m_currentState = MENU;

	TheInputHandler::Instance()->initialiseJoysticks();

	is_running = true;

	return true;
}

void Game::render(){
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	draw();
	SDL_RenderPresent(m_pRenderer);
}

void Game::draw(){
	for(GameObject* gameObject : m_gameObjects){
		gameObject->draw();
	}
}

void Game::update(){
	m_currentFrame = int(SDL_GetTicks()/100 % 6);
	m_pGameStateMachine->update();
	for(GameObject* gameObject : m_gameObjects){
		gameObject->update();
	}
}

void Game::clean(){
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	IMG_Quit();
	SDL_Quit();
}

void Game::handleEvents(){
	TheInputHandler::Instance()->update();

	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)){
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::quit(){
	is_running = false;
}
