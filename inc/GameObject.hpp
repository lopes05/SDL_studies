#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <LoaderParams.hpp>
#include <TextureManager.hpp>
#include <SDL2/SDL.h>

class GameObject{
public:
	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;

	virtual void load(const LoaderParams* pParams) = 0;

protected:
	GameObject(){}
	virtual ~GameObject(){}
};

#endif