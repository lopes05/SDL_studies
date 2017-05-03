#ifndef __LEVELPARSER__
#define __LEVELPARSER__

#include <Level.hpp>
#include "tinyxml.h"

class LevelParser{

public:
	Level* parseLevel(const char* levelFile);


private:
	void parseTilesets(TiXmlElement* pTileSetRoot, std::vector<Tileset> *pTileSets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers,
		const std::vector<Tileset> *pTileSets);
	void parseTextures(TiXmlElement* pTextureRoot);
	void parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers);

	int m_tileSize;
	int m_width;
	int m_height;

};

#endif