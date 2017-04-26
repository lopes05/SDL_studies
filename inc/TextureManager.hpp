#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class TextureManager{

	public:
		
		static TextureManager* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new TextureManager();
				return s_pInstance;
			}
			return s_pInstance;
		}	

		bool load(std::string fileName, std::string id, SDL_Renderer *p_Renderer);
		void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *p_Renderer,
			SDL_RendererFlip flip = SDL_FLIP_NONE);
		void drawFrame(std::string id, int x, int y, int width, int height, int currentRow,
			int currentFrame, SDL_Renderer *p_Renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


	private:
		TextureManager(){}
		~TextureManager(){}
		static TextureManager *s_pInstance;
		std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif