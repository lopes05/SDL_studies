#include <GameOverState.hpp>
#include <Game.hpp>
#include <TextureManager.hpp>
#include <InputHandler.hpp>
#include <PlayState.hpp>
#include <AnimatedGraphic.hpp>
#include <MenuButton.hpp>
#include <MainMenuState.hpp>
#include <StateParser.hpp>

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->update();
	}
}

void GameOverState::render(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->draw();
	}
}

void GameOverState::s_gameOverToMain(){
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay(){
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter(){
	StateParser stateParser;

	stateParser.parseState("test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);

	setCallbacks(m_callbacks);

	std::cout << "Enter Game over State\n";
	return true;
}

bool GameOverState::onExit(){
	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	for(int i = 0; i < (int) m_textureIDList.size(); i++){
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	
	std::cout << "exiting gameoverState\n";
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks){
	// go through the game objects
	for(int i = 0; i < (int)m_gameObjects.size(); i++){
		if(dynamic_cast<MenuButton*>(m_gameObjects[i])){
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
