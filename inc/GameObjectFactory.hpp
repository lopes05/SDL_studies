#ifndef __GAMEOBJECTFACTORY__
#define __GAMEOBJECTFACTORY__

#include <SDLGameObject.hpp>
#include <iostream>
#include <BaseCreator.hpp>
#include <map>

class GameObjectFactory{
	public:
		static GameObjectFactory* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new GameObjectFactory();
				return s_pInstance;
			}

			return s_pInstance;
		}

		bool registerType(std::string typeID, BaseCreator* pCreator);
		GameObject* create(std::string typeID);

	private:
		GameObjectFactory() {}
		static GameObjectFactory* s_pInstance;
		std::map<std::string, BaseCreator*> m_creators;

};

typedef GameObjectFactory TheGameObjectFactory;

#endif