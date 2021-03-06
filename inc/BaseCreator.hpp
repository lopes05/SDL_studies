#ifndef __BASECREATOR__
#define __BASECREATOR__

#include <string>
#include <map>
#include <GameObject.hpp>

class BaseCreator{
	public:
		virtual GameObject* createGameObject() const = 0;
		virtual ~BaseCreator() {}
};

#endif