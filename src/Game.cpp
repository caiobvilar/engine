#include "../include/Game.hpp"

Game::Game()
{
	//Nothing special.
}

Game::~Game()
{
	this->Clean();
}

void Game::Init()
{
	//calls configuration routine
	//starts singletons
	this->mainWindow = new WindowModule();
	this->mainWindow->configure();
	if(this->mainWindow->init() < 0)
	{
		//failed to start WindowModule
	}
	
	this->inputManager = new InputManager();
	this->inputManager->configure();
	if(this->inputManager->init() < 0)
	{
	//failed to start InputManager
	}
	/*
	this->audioModule = new AudioModule();
	if(this->audioModule == nullptr)
	{
	//failed to start AudioModule
	}
	*/
	this->running=true;
	//
}

void Game::Clean()
{
	delete this->mainWindow;
	this->mainWindow = nullptr;

	delete this->inputManager;
	this->inputManager = nullptr;

	//Calling GameObject cleanup
	if(!this->GameObjects.empty())
	{
		std::vector<GameObject*>::iterator GObItr;
		for(GObItr = this->GameObjects.begin();
				GObItr != this->GameObjects.end();
				GObItr++)
		{
			(*GObItr)->clean();
		}
		if(this->GameObjects.empty())
		{
			this->GameObjects.clear();
		}
		else
		{
			//something happened
			//and an object did not clean
			//itself.
		}
	}
	SDL_Quit();
}

void Game::Update()
{
	std::vector<GameObject*>::iterator GObItr;
	for(GObItr = this->GameObjects.begin();
			GObItr != this->GameObjects.end();
			GObItr++)
	{
		(*GObItr)->update();
	}
	//	this->inputManager->dispatchEvents();	
}

void Game::Render()
{
	//TODO: find out how to handle all the
	//rendering pendencies from the GObjects
}

void Game::HandleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				this->mainWindow->clean();
				this->running=false;
				break;
			default:
				break;
		}
	}
}

bool Game::isRunning()
{
	return this->running;
}
