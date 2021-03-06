#include <PlayState.hpp>
#include <iostream>
#include <InputHandler.hpp>
#include <Game.hpp>
#include <GameOverState.hpp>
#include <PauseState.hpp>
#include <MenuButton.hpp>
#include <StateParser.hpp>

const std::string PlayState::s_playID = "PLAY";
Level *pLevel = NULL;

void PlayState::update(){
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->update();
	}

	if(pLevel != NULL){
		pLevel->update();
	}

	/*if(checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), 
			dynamic_cast<SDLGameObject*> (m_gameObjects[1]))){
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}*/
}

void PlayState::render(){

	if(pLevel != NULL){
		pLevel->render();
	}

}

bool PlayState::onEnter(){
	
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("assets/mapa2.tmx");

	std::cout << "Entered play state\n";
	return true;
}

bool PlayState::onExit(){
	for(int i = 0; i < (int)m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	
	for(int i = 0; i < (int)m_textureIDList.size(); i++){
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exit playstate\n";
	return true;
}


bool PlayState::checkCollision(SDLGameObject *p1, SDLGameObject *p2){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if(bottomA <= topB) return false;
	if(topA >= bottomB) return false;
	if(rightA <= leftB) return false;
	if(leftA >= rightB) return false;

	return true;

}