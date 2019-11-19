/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GPL 3.0
//	Filename: main.cpp
/////////////////////////////////////////////////////////////////
#include "../include/Game.hpp"
#include <iomanip>
#define	FPS	60
#define	FRAME_DELAY	1000/FPS

Game* GameInstance = nullptr;

int main(int argc, char *argv[])
{
	GameInstance = new Game();
	uint32_t frameStart,frameTime;
	GameInstance->Init("Main Window",0,0,1024,780);
	while(GameInstance->isRunning()) // Main Loop
	{
		frameStart = SDL_GetTicks();
		GameInstance->HandleEvents();
		GameInstance->Update();
		GameInstance->Render();
		frameTime = SDL_GetTicks() - frameStart;
		if(FRAME_DELAY > frameTime)
		{
			SDL_Delay((int) (FRAME_DELAY - frameTime));
		}
		/*
		std::cout << "\r"
							<< std::setw(3) << std::setfill('0')
							<< "FPS: " << frameTime
							<< std::setw(3) << std::flush;
		*/
	}
	GameInstance->Cleanup();
	delete GameInstance;
	return 0;
}
