#ifndef __PLAYSTATE__
#define __PLAYSTATE__

#include <GameState.hpp>
#include <SDLGameObject.hpp>
#include <GameOverState.hpp>
#include <PauseState.hpp>

class PlayState : public GameState{
	public:
		virtual void update();
		virtual void render();
		virtual bool onEnter();
		virtual bool onExit();
		
		virtual std::string getStateID() const {return s_playID;}
	private:
		bool checkCollision(SDLGameObject *p1, SDLGameObject *p2);
		static const std::string s_playID;
		std::vector<GameObject*> m_gameObjects;
};

#endif