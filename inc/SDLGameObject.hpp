#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__

#include <GameObject.hpp>
#include <Vector2D.hpp>
#include <LoaderParams.hpp>

class SDLGameObject : public GameObject{
public:
	SDLGameObject();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams *pParams);

	Vector2D& getPosition() {return m_position;}
	int getWidth() const {return m_width;}
	int getHeight() const {return m_height;}
	int getNumFrames() const {return m_numFrames;}
	
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;
	std::string m_textureID;
};

#endif