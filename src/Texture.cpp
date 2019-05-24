#include "../include/Texture.hpp"



Texture::Texture()
{
	this->texture = nullptr;
	this->imgWidth=0;
	this->imgHeight=0;
}

Texture::~Texture()
{
	//Deallocate stuff
	if(this->texture != nullptr)
	{
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
		this->imgWidth=0;
		this->imgHeight=0;

	}
}

bool Texture::loadFromImage(std::string imgPath)
{
	SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(imgPath.c_str());
	if(loadedSurface == NULL)
	{
		std::cout << "[Texture]: unable to create texture from " << imgPath.c_str()
							<< "! SDL Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		this->imgWidth = loadedSurface->w;
		this->imgHeight = loadedSurface->w=h;
	}
}

void Texture::render(SDL_Renderer* renderInst,int x,int y,SDL_Rect * clip=nullptr)
{

}

int Texture::getWidth()
{
	return this->imgWidth;
}
int Texture::getHeight()
{
	return this->imgHeight;
}
