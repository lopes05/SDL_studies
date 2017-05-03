#include <ObjectLayer.hpp>

void ObjectLayer::render(){
	for(int i = 0; i < (int) m_gameObjects.size(); ++i){
		m_gameObjects[i]->draw();
	}
}

void ObjectLayer::update(){
	for(int i = 0; i < (int) m_gameObjects.size(); i++){
		m_gameObjects[i]->update();
	}
}