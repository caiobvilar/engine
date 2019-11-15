#ifndef _TEXTUREMANAGER_HPP_
#define _TEXTUREMANAGER_HPP_

#include "Game.hpp"

class TextureManager
{
	public:
		static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* render);

};




#endif //_TEXTUREMANAGER_HPP_
