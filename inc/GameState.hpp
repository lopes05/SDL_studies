#ifndef __GAMESTATE__
#define __GAMESTATE__

#include <string>
#include <vector>
#include <iostream>
#include <SDLGameObject.hpp>

enum game_states{
	MENU = 0,
	PLAY = 1,
	GAMEOVER = 2
};

class GameState{
	public:
		virtual void update() = 0;
		virtual void render() = 0;
		virtual bool onEnter() = 0;
		virtual bool onExit() = 0;
		virtual std::string getStateID() const = 0;

		virtual ~GameState(){}

	protected:
		std::vector<std::string> m_textureIDList;

};

#endif