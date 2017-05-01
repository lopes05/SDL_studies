#ifndef __ENEMY__
#define __ENEMY__

#include <SDLGameObject.hpp>

class Enemy : public SDLGameObject{
public:
	Enemy();

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
};

#endif