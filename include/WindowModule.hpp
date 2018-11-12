//////////////////////////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main window class that handles all windows and window related events
//	License: GLP 3.0
//	Filename: WindowModule.hpp
//////////////////////////////////////////////////////////////////////////////////////
#ifndef _WINDOWMODULE_HPP
#define _WINDOWMODULE_HPP

#include <cstdint>	// Regarding uint32_t type
#include <SDL2/SDL.h>
#include "GameEntity.hpp"

class WindowModule : public GameEntity
{
	private:

		const char *windowTitle = "Window Module";
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
