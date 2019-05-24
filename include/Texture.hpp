#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include "GameObject.hpp"

class Texture: public GameObject
{
	private:
		
		//Hardware texture
		SDL_Texture* texture;
		//Source image dimensions
		int imgWidth;
		int imgHeight;


	public:
		
		Texture();
		
		~Texture();

		bool loadFromImage(std::string imgPath);

		void render(SDL_Renderer* renderInst,int x,int y,SDL_Rect * clip=nullptr);

		int getWidth();
		int getHeight();


};
