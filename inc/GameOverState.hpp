#ifndef __GAMEOVERSTATE__
#define __GAMEOVERSTATE__

#include <SDLGameObject.hpp>
#include <MenuState.hpp>
#include <PlayState.hpp>
#include <AnimatedGraphic.hpp>

class GameOverState : public GameState{
	public:
		virtual void update();
		virtual void render();
		virtual bool onEnter();
		virtual bool onExit();
		virtual std::string getStateID() const {return s_gameOverID;}
	private:
		static void s_gameOverToMain();
		static void s_restartPlay();
		static const std::string s_gameOverID;
		std::vector<GameObject*> m_gameObjects;

};

#endif