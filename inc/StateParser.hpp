#ifndef __STATEPARSER__
#define __STATEPARSER__

#include <iostream>
#include <vector>
#include <string>
#include "tinyxml.h"
#include <GameObject.hpp>
#include <GameObjectFactory.hpp>

class StateParser{
	public:
		bool parseState(const char* stateFile, std::string stateID, 
			std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);

	private:
		void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects);
		void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs);

};

#endif