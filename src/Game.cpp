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

	std::cout << "Init OK!\n";

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());
	//m_pMenuObj1 = new MenuObject();
	//m_pMenuObj2 = new MenuObject();

	m_currentState = MENU;

	//m_pPlayer = new Player();
	//m_pEnemy = new Enemy();


	TheTextureManager::Instance()->load("assets/cat.png", "animate", m_pRenderer);
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	TheInputHandler::Instance()->initialiseJoysticks();

	is_running = true;

	return true;
}

void Game::render(){
	SDL_RenderClear(m_pRenderer);
	draw();
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::draw(){
	for(GameObject* gameObject : m_gameObjects){
		gameObject->draw();
	}
}

void Game::update(){
	m_pGameStateMachine->update();
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
