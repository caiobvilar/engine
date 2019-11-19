#include "../include/Game.hpp"
#include "../include/TextureManager.hpp"
#include "../include/Player.hpp"
/////CONSTRUCTOR/////
Game::Game()
{}
/////DESTRUCTOR//////
Game::~Game()
{}

SDL_Texture* playerTx;
SDL_Rect srcRect,destRect;

SDL_Renderer* Game::mainRenderer = nullptr;

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
				SDL_SetRenderDrawColor(this->mainRenderer,188,198,214,255);
				this->running = true;
				std::cout << "[GAME]: Game is now running." << std::endl;
			}
		}
	}
	///////////Texture Loading////////
	//playerTx = TextureManager::LoadTexture("../art/player.png",this->mainRenderer);
	GameObject* obj = new Player("../art/player.png",this->mainRenderer,0, 0);
	GameObject* obj1 = new Player("../art/player.png",this->mainRenderer,0, 68);
	GameObject* obj2 = new Player("../art/player.png",this->mainRenderer,0, 136);
	GameObject* obj3 = new Player("../art/player.png",this->mainRenderer,0, 204);
	GameObject* obj4 = new Player("../art/player.png",this->mainRenderer,0, 272);
	GameObject* obj5 = new Player("../art/player.png",this->mainRenderer,0, 340);
	GameObject* obj6 = new Player("../art/player.png",this->mainRenderer,0, 408);
	GameObject* obj7 = new Player("../art/player.png",this->mainRenderer,0, 476);
	this->Objects.push_back(obj);
	this->Objects.push_back(obj1);
	this->Objects.push_back(obj2);
	this->Objects.push_back(obj3);
	this->Objects.push_back(obj4);
	this->Objects.push_back(obj5);
	this->Objects.push_back(obj6);
	this->Objects.push_back(obj7);

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

			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_q)
				{
					this->running=false;
					break;
				}
		}
	}
}
void Game::Render()
{
	SDL_RenderClear(this->mainRenderer);
	//Do rendering stuff
	//SDL_RenderCopy(this->mainRenderer,playerTx,NULL,&destRect);
	std::vector<GameObject*>::iterator Objects_itr;
	for(Objects_itr = this->Objects.begin();
			Objects_itr != this->Objects.end();
			Objects_itr++)
	{
		(*Objects_itr)->draw(this->mainRenderer);
	}
	//loop through the draw() functions of objects vector
	SDL_RenderPresent(this->mainRenderer);
}
void Game::Update()
{
	std::vector<GameObject*>::iterator Objects_itr;
	for(Objects_itr = this->Objects.begin();
			Objects_itr != this->Objects.end();
			Objects_itr++)
	{
		(*Objects_itr)->update();
	}
}
void Game::Cleanup()
{
	//Destroy Game Objects and components
	std::vector<GameObject*>::iterator Objects_itr;
	for(Objects_itr = this->Objects.begin();
			Objects_itr != this->Objects.end();
			Objects_itr++)
	{
		delete (*Objects_itr);
		(*Objects_itr) = nullptr;
	}
	//Destroy SDL Objects and components
	SDL_DestroyWindow(this->mainWindow);
	SDL_DestroyRenderer(this->mainRenderer);
	SDL_Quit();
	std::cout << "\nGame Object cleaned up!" << std::endl;
}
bool Game::isRunning()
{
	return this->running;
}
