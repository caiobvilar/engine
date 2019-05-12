#include "../include/Game.hpp"

Game::Game()
{}
Game::~Game()
{}
void Game::Init(std::string winName,int win_x,int win_y,int win_width,int win_height)
{
	this->windowName = winName;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "[ERROR]: SDL video could not be initialized! SDL_Error: " << SDL_GetError() << std::endl;
		this->running=false;
	}
	else
	{
		std::cout << "[GAME]: SDL video succesfuly initialized." << std::endl;
		this->mainWindow = SDL_CreateWindow(this->windowName.c_str(),win_x,win_y,win_width,win_height,0);
		if(!this->mainWindow)
		{
			std::cout << "[ERROR]: Window could not be created! SDL_Error: " << SDL_GetError()<< std::endl;
			this->running=false;
		}
		else
		{
			std::cout << "[GAME]: Window succesfuly created." << std::endl;
			this->mainRenderer = SDL_CreateRenderer(this->mainWindow,-1,0);
			if(!this->mainRenderer)
			{
				std::cout << "[ERROR]: Could not create renderer! SDL_Error: " << SDL_GetError() << std::endl;
				this->running=false;
			}
			else
			{
				std::cout << "[GAME]: Renderer succesfuly created." << std::endl;
			}
		}
	}
	this->running = true;
	std::cout << "[GAME]: Game is now running." << std::endl;
}
void Game::HandleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				this->running=false;
				break;
		}
	}
}
void Game::Render()
{
	SDL_RenderClear(this->mainRenderer);
	//Do rendering stuff
	SDL_RenderPresent(this->mainRenderer);
}
void Game::Update()
{
}
void Game::Cleanup()
{
	std::vector<GameObject*>::iterator Objects_itr;
	for(Objects_itr = this->Objects.begin();
			Objects_itr != this->Objects.end();
			Objects_itr++)
	{
		delete (*Objects_itr);
		(*Objects_itr) = nullptr;
	}
	SDL_DestroyWindow(this->mainWindow);
	SDL_DestroyRenderer(this->mainRenderer);
	SDL_Quit();
	std::cout << "Game Object cleaned up!" << std::endl;
}
bool Game::isRunning()
{
	return this->running;
}
void Game::setRunning(bool state)
{
	this->running = state;
}
