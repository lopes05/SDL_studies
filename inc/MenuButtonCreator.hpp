#ifndef __MENUBUTTONCREATOR__
#define __MENUBUTTONCREATOR__

#include <MenuButton.hpp>
#include <BaseCreator.hpp>

class MenuButtonCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new MenuButton();
	}
};

#endif