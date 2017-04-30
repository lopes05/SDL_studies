#include <PauseState.hpp>
#include <TextureManager.hpp>
#include <InputHandler.hpp>
#include <Game.hpp>

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain(){
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
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

bool PauseState::onEnter(){
	if(!TheTextureManager::Instance()->load("assets/resumeButton.png", "resumebutton",
		TheGame::Instance()->getRenderer())){
		return false;
	}

	if(!TheTextureManager::Instance()->load("assets/menuButton.png", "mainbutton", 
		TheGame::Instance()->getRenderer())){
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"),
	 									s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,200, 80, "resumebutton"),
										 s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit(){
	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}