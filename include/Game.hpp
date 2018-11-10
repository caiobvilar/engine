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

///////////////////////////

class Game
{
	public:

		Game();
		~Game();

	private:

		bool running;																//Holds game running state
};
#endif //_GAME_HPP_
