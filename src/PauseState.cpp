#include <PauseState.hpp>
#include <TextureManager.hpp>
#include <InputHandler.hpp>
#include <Game.hpp>
#include <MenuButton.hpp>
#include <StateParser.hpp>

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain(){
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay(){
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->update();
	}
}

void PauseState::render(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->draw();
	}
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks){
	// go through the game objects
	for(int i = 0; i < (int)m_gameObjects.size(); i++){
		if(dynamic_cast<MenuButton*>(m_gameObjects[i])){
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

bool PauseState::onEnter(){

	StateParser stateParser;
	stateParser.parseState("test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);
	setCallbacks(m_callbacks);

	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit(){
	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	for(int i = 0; i < (int)m_textureIDList.size(); i++){
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}