#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include <SDLGameObject.hpp>

class AnimatedGraphic : public SDLGameObject{
	public:
		AnimatedGraphic();
		void update();
		void draw();
		void clean();
		void load(const LoaderParams* pParams);
	private:
		int m_animSpeed;


};

#endif