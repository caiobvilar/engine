/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GLP 3.0
//	Filename: main.cpp
/////////////////////////////////////////////////////////////////
#include "../include/WindowModule.hpp"
#include "../include/InputHandler.hpp"

#define	FPS	60
#define	DELAY_TIME	1000.0f/FPS


int main(int argc, char *argv[])
{
	InputHandler* Input = new InputHandler();
	WindowModule* Window = new WindowModule(800,600);
	Input->attachObserver(Window,Window);
	bool running = true;
	uint32_t frameStart,frameTime;
	while(running) // Main Loop
	{
		frameStart = SDL_GetTicks();
		Input->handleInputs();
		Window->update();
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME)
		{
			SDL_Delay((int) (DELAY_TIME - frameTime));
		}
	}
	return 0;
}
