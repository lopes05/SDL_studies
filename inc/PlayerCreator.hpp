#ifndef __PLAYERCREATOR__
#define __PLAYERCREATOR__

#include <BaseCreator.hpp>
#include <Player.hpp>

class PlayerCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new Player();	
	}
};

#endif