#include <MainMenuState.hpp>
#include <StateParser.hpp>
#include <Game.hpp>

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->update();
	}
}

void MainMenuState::render(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->draw();
	}
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		if(dynamic_cast<MenuButton*>(m_gameObjects[i])){
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

bool MainMenuState::onEnter(){
	StateParser stateParser;
	stateParser.parseState("xml/test.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);

	setCallbacks(m_callbacks);
	std::cout << "entering menu state\n";
	return true;
}

bool MainMenuState::onExit(){
	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for(int i = 0; i < (int) m_textureIDList.size(); i++){
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exiting menu state \n";
	return true;
}

void MainMenuState::s_menuToPlay(){
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu(){
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}