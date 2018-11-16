/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GLP 3.0
//	Filename: main.cpp
/////////////////////////////////////////////////////////////////
#include "../include/Game.hpp"

#define	FPS	60
#define	DELAY_TIME	1000.0f/FPS


int main(int argc, char *argv[])
{
	Game *gameInstance = new Game();
	gameInstance->Init();
	uint32_t frameStart,frameTime;
	while(gameInstance->isRunning()) // Main Loop
	{
		frameStart = SDL_GetTicks();
		//Handles Events
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME)
		{
			SDL_Delay((int) (DELAY_TIME - frameTime));
		}
	}
	gameInstance->Shutdown();
	delete gameInstance;
	return 0;
}
