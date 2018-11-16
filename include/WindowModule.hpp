//////////////////////////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main window class that handles all windows and window related events
//	License: GLP 3.0
//	Filename: WindowModule.hpp
//////////////////////////////////////////////////////////////////////////////////////
#ifndef _WINDOWMODULE_HPP
#define _WINDOWMODULE_HPP

#include <cstdint>	// Regarding uint32_t type
#include <iostream> // Regarding cout
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class WindowModule
{
	private:

		SDL_Window* mainWindow = NULL;
		SDL_Surface* mainSurface = NULL;
		int windowWidth=0;
		int windowHeight=0;


	public:

		WindowModule(int wid,int hei);
		~WindowModule();
		void setWidth(int width);
		void setHeight(int height);
		int getWidth();
		int getHeight();
		void cleanup();
		void update();
};

#endif //_WINDOWMODULE_HPP
