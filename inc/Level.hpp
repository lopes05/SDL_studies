#ifndef __LEVEL__
#define __LEVEL__

#include <string>
#include <vector>
#include <Layer.hpp>

struct Tileset{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Level{
public:
	~Level() {}

	void update();
	void render();

	std::vector<Tileset>* getTileSets() { return &m_tileSets; }
	std::vector<Layer*>* getLayers() { return &m_layers; }

private:
	std::vector<Tileset> m_tileSets;
	std::vector<Layer*> m_layers;
	friend class LevelParser;
	Level() {}
};


#endif