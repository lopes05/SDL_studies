#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include <SDLGameObject.hpp>

class AnimatedGraphic : public SDLGameObject{
	public:
		AnimatedGraphic(const LoaderParams* pParams	, int animSpeed);
		void update();
		void draw();
		void clean();
	private:
		int m_animSpeed;


};

#endif