#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[])
{
	SDL_Window *main_Win;
	SDL_Renderer *main_Render;
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "[ENGINE]: SDL succesfully initialized." << std::endl;
		main_Win = SDL_CreateWindow("HELLO xD",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				640,
				480,
				SDL_WINDOW_SHOWN);
		if(main_Win != 0)
		{
			std::cout << "[ENGINE]: SDL_WINDOW succesfully created." << std::endl;
			main_Render = SDL_CreateRenderer(main_Win,-1,0);
			std::cout << "[ENGINE]: SDL_RENDERER succesfully created." << std::endl;
		}
		else
		{
			std::cout << "[ENGINE]: SDL failed to initialize." << std::endl;
			return 1;
		}
		SDL_SetRenderDrawColor(main_Render,0,0,0,255);
		SDL_RenderClear(main_Render);
		SDL_RenderPresent(main_Render);
		SDL_Delay(3000);
		std::cout << "[ENGINE]: 3 seconds delay..." << std::endl;
		SDL_DestroyRenderer(main_Render);
		std::cout << "[ENGINE]: destroyed renderer..." << std::endl;
		SDL_DestroyWindow(main_Win);
		std::cout << "[ENGINE]: destroyed window..." << std::endl;
		SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
		SDL_Quit();
		std::cout << "[ENGINE]: quit SDL." << std::endl;
	}

	return 0;
}
