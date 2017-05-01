#ifndef __ENEMYCREATOR__
#define __ENEMYCREATOR__

#include <Enemy.hpp>
#include <BaseCreator.hpp>

class EnemyCreator : public BaseCreator{
	GameObject* createGameObject() const {
		return new Enemy();
	}
};

#endif