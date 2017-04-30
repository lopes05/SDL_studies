#include <GameOverState.hpp>
#include <Game.hpp>
#include <TextureManager.hpp>
#include <InputHandler.hpp>
#include <PlayState.hpp>
#include <AnimatedGraphic.hpp>

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain(){
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay(){
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter(){
	if(!TheTextureManager::Instance()->load("assets/gameover.png", "gameovertext",
		TheGame::Instance()->getRenderer())){
		return false;
	}

	if(!TheTextureManager::Instance()->load("assets/menuButton.png", "mainbutton",
		TheGame::Instance()->getRenderer())){
		return false;
	}

	if(!TheTextureManager::Instance()->load("assets/restart.png", "restartbutton",
		TheGame::Instance()->getRenderer())){
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30,
		"gameovertext", 2), 2);

	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, 
		"restartbutton"), s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "Enter Game over State\n";
	return true;
}

bool GameOverState::onExit(){
	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("gameOverText");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");
	std::cout << "exiting gameoverState\n";
	return true;
}
