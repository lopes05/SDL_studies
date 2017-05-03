#include <Level.hpp>

void Level::render(){
	for(int i = 0; i < (int) m_layers.size(); ++i){
		m_layers[i]->render();
	}
}

void Level::update(){
	for(int i = 0; i < (int) m_layers.size(); ++i){
		m_layers[i]->update();
	}
}