#ifndef _GAME_HPP_
#define _GAME_HPP_

//C++ Basics
#include <pthread.h>
#include <vector>
//SDL Libs//////////////////
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
///////CORE LIBS////////////
#include "InputHandler.hpp"
#include "WindowModule.hpp"
///////////////////////////

class Game
{
	public:

		Game();
		~Game();

	private:

		bool running;																//Holds game running state
		InputHandler* Inputmanager;
		WindowModule* WindowManager;
		void Init();
		void Shutdown();
};
#endif //_GAME_HPP_
