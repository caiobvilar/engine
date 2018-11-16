#ifndef _GAME_HPP_
#define _GAME_HPP_

//C++ Basics
#include <pthread.h>
#include <vector>
//SDL Libs//////////////////
///////CORE LIBS////////////
#include "InputHandler.hpp"
#include "WindowModule.hpp"
///////////////////////////

class Game
{
	public:

		Game();
		~Game();
		void Init();
		void Shutdown();
		bool isRunning();
	private:

		bool running;																//Holds game running state
		InputHandler* Inputmanager;
		WindowModule* WindowManager;
};
#endif //_GAME_HPP_
