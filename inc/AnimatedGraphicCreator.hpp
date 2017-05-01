#ifndef __ANIMATEDGRAPHICCREATOR__
#define __ANIMATEDGRAPHICCREATOR__

#include <BaseCreator.hpp>
#include <AnimatedGraphic.hpp>

class AnimatedGraphicCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new AnimatedGraphic();	
	}

};

#endif