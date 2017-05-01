#include <GameObjectFactory.hpp>

GameObjectFactory* GameObjectFactory::s_pInstance = 0;

bool GameObjectFactory::registerType(std::string typeID, BaseCreator* pCreator){
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

	// if the type is already registered, do nothing
	if(it != m_creators.end())
	{
		delete pCreator;
		return false;
	}
	m_creators[typeID] = pCreator;
	return true;
}

GameObject* GameObjectFactory::create(std::string typeID){
	//Must found Creator to be able to create game object
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);
	if(it == m_creators.end()){
		return NULL;
	}
	
	BaseCreator* pCreator = (*it).second;
	return pCreator->createGameObject();
}