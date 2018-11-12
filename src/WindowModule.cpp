#include "../include/WindowModule.hpp"
#include <iostream> //TODO: remove and use the LogModule to handle logging stuff

int WindowModule::init()
{
	std::cout << "[SYSTEM]: Initing SDL..." << std::endl;
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "[ERROR]: failed to init.[" << SDL_GetError() << "]" << std::endl;
		return -1;
	}
	std::cout << "[SYSTEM]: Creating Window..." << std::endl;
	this->MainWindow = SDL_CreateWindow(
			this->windowTitle,
			this->Xoffset,
			this->Yoffset,
			this->SCREEN_WIDTH,
			this->SCREEN_HEIGHT,
			this->WinFlags);
	std::cout << "[SYSTEM]: checking window creation..." << std::endl;
	if(this->MainWindow == nullptr)
	{
		std::cout << "[ERROR]: Failed on SDL_CreateWindow().[" << SDL_GetError() << "]" << std::endl;
		return -1;
	}
	std::cout << "[SYSTEM]: window created succesfully." << std::endl;
	return 0;
}

void WindowModule::clean()
{
	std::cout << "[SYSTEM]: shuting down WindowModule..." << std::endl;
	if(this->MainWindow)
	{
		SDL_DestroyWindow(this->MainWindow);
		this->MainWindow = nullptr;
	}
	std::cout << "[SYSTEM]: quitting SDL..." << std::endl;
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	std::cout << "[SYSTEM]: Graphics finished." << std::endl;
}

void WindowModule::onNotify(SDL_Event event)
{
	switch(event.type)
	{
		case SDL_Quit:
			this->clean();
			break;
		case SDL_WindowEvent:
			this->
	}
}

void WindowModule::configure()
{
}


