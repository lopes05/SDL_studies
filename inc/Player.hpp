#ifndef __PLAYER__
#define __PLAYER__

#include <SDLGameObject.hpp>

class Player : public SDLGameObject{
public:
	Player();
	
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);

private:
	void handleInput();

};

#endif