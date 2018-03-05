#include "../include/Game.hpp"
#define	FPS	60
#define	DELAY_TIME	1000.0f/FPS

int main(int argc, char *argv[])
{
	Game *game = new Game();
	game->Init();
	uint32_t frameStart,frameTime;

	while(game->isRunning()) // Main Loop
	{
		frameStart = SDL_GetTicks();
		//Handles Events
		game->HandleEvents();
		//Update States
		game->Update();
		//Render changes
		game->Render();
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME)
		{
			SDL_Delay((int) (DELAY_TIME - frameTime));
		}
	}
	delete game; //Calls game Clean() method
	game = NULL;
	return 0;
}
