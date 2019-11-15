#include "../include/TextureManager.hpp"



SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* render)
{
	SDL_Surface* tmpSurf = IMG_Load(filename);
	if(!tmpSurf)
	{
		std::cout << SDL_GetError() << std::endl;
		return nullptr;
	}
	SDL_Texture* textr = SDL_CreateTextureFromSurface(render,tmpSurf);
	if(!textr)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_FreeSurface(tmpSurf);
		return nullptr;
	}
	SDL_FreeSurface(tmpSurf);
	return textr;
}
