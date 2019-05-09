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
	Game* GameInstance = new Game();
	uint32_t frameStart,frameTime;
	GameInstance->Init("Main Window",0,0,800,600);
	const uint8_t *kbdkeystates= nullptr;
	while(GameInstance->isRunning()) // Main Loop
	{
		frameStart = SDL_GetTicks();
		GameInstance->HandleEvents();
		GameInstance->Update();
		GameInstance->Render();
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME)
		{
			SDL_Delay((int) (DELAY_TIME - frameTime));
		}
		std::cout << "FPS: " << frameTime << std::endl;
		kbdkeystates = SDL_GetKeyboardState(NULL);
		if(kbdkeystates[SDL_SCANCODE_Q])
		{
			GameInstance->setRunning(false);
		}
	}
	GameInstance->Cleanup();
	delete GameInstance;
	return 0;
}
