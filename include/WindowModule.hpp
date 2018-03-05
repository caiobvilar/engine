#ifndef _WINDOWMODULE_HPP
#define _WINDOWMODULE_HPP

#include <cstdint>	// Regarding uint32_t type
#include <SDL2/SDL.h>

class WindowModule
{
	private:

		//TODO: fill all this data with
		//the Configure() method, while reading
		//from a config.json file.
		const char *windowTitle = "SDL Testing";
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		const int Xoffset = SDL_WINDOWPOS_CENTERED;
		const int Yoffset = SDL_WINDOWPOS_CENTERED;
		uint32_t WinFlags = SDL_WINDOW_SHOWN;
		SDL_Window *MainWindow;
		SDL_Renderer *MainRenderer;

	public:

		void clean(); 	// Returns 0 if clean was succesfull, -1 if not
		int init();			// Returns 0 if Initiation was succesfull, -1 if not
		void configure();
};

#endif //_WINDOWMODULE_HPP
