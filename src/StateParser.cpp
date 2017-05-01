#include <StateParser.hpp>
#include <Game.hpp>
#include <TextureManager.hpp>
#include <GameObjectFactory.hpp>
#include <iostream>

using namespace std;

bool StateParser::parseState(const char *stateFile, std::string stateID, 
	std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs){

	TiXmlDocument xmlDoc;

	if(!xmlDoc.LoadFile(stateFile)){
		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}
	
	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;
	
	// get this states root node and assign it to pStateRoot
	for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
		if(e->Value() == stateID){
			pStateRoot = e;
		}
	}
	
	// pre declare the texture root
	TiXmlElement* pTextureRoot = 0;
	
	// get the root of the texture elements
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; 
		e = e->NextSiblingElement()){
		if(e->Value() == std::string("TEXTURES")){
			pTextureRoot = e;
		}
	}
	
	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);
	
	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;
	
	// get the root node and assign it to pObjectRoot
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; 
		e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("OBJECTS")){
			pObjectRoot = e;
		}
	}
	// now parse the objects
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseTextures(TiXmlElement *pStateRoot, 
	std::vector<std::string> *pTextureIDs){
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; 
		e = e->NextSiblingElement())
	{
		string fileNameAttribute = e->Attribute("filename");
		string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute);
		TheTextureManager::Instance()->load(fileNameAttribute, idAttribute,
			TheGame::Instance()->getRenderer());
	}
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, 
	std::vector<GameObject*> *pObjects){

	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; 
		e = e->NextSiblingElement()){
		int x, y, width, height, numFrames, callbackID, animSpeed;
		string textureID;

		e->Attribute("x", &x);
		e->Attribute("y", &y); 
		e->Attribute("width", &width); 
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames); 
		e->Attribute("callbackID", &callbackID); 
		e->Attribute("animSpeed", &animSpeed);
		
		textureID  = e->Attribute("textureID");

		GameObject* pGameObject = TheGameObjectFactory::Instance()->
									create(e->Attribute("type"));

		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames,
			callbackID, animSpeed));

		pObjects->push_back(pGameObject);

	}

}