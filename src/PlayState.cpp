#include <PlayState.hpp>
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update(){

}

void PlayState::render(){


}

bool PlayState::onEnter(){
	std::cout << "Entered play state\n";
	return true;
}

bool PlayState::onExit(){
	std::cout << "exit playstate\n";
	return true;
}


