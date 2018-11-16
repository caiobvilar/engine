#include "../include/WindowModule.hpp"


WindowModule::WindowModule(int width,int height)
{
	this->setWidth(width);
	this->setHeight(height);
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "[ERROR]: SDL could not initialize!-> SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		this->mainWindow = SDL_CreateWindow("Main Window",
																				SDL_WINDOWPOS_UNDEFINED,
																				SDL_WINDOWPOS_UNDEFINED,
																				this->getWidth(),
																				this->getHeight(),
																				SDL_WINDOW_SHOWN);
		if(this->mainWindow == NULL)
		{
			std::cout << "[ERROR]: Window could not be created!-> SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			this->mainSurface = SDL_GetWindowSurface(this->mainWindow);
		}
	}
}

WindowModule::~WindowModule()
{
	this->cleanup();
	SDL_DestroyWindow(this->mainWindow);
}

void WindowModule::setWidth(int width)
{
	this->windowWidth = width;
}
void WindowModule::setHeight(int height)
{
	this->windowHeight = height;
}
int WindowModule::getWidth()
{
	return this->windowWidth;
}
int WindowModule::getHeight()
{
	return this->windowHeight;
}
void WindowModule::update()
{
	SDL_UpdateWindowSurface(this->mainWindow);
}

void WindowModule::cleanup()
{
	//cleanup all containers.
}
