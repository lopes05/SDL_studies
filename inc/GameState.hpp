#ifndef __GAMESTATE__
#define __GAMESTATE__

#include <string>

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

	private:

};

#endif