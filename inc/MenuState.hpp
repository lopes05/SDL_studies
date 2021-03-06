#ifndef __MENUSTATE__
#define __MENUSTATE__

#include <GameState.hpp>
#include <vector>
#include <SDLGameObject.hpp>

class MenuState : public GameState{
	protected:
		typedef void(*Callback) ();
		virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
		std::vector<Callback> m_callbacks;

};

#endif