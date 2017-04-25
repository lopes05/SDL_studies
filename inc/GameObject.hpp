#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <LoaderParams.hpp>
#include <TextureManager.hpp>

class GameObject{
public:
	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;

protected:
	GameObject(const LoaderParams *pParams){}
	virtual ~GameObject(){}
};

#endif