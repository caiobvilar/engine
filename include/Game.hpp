#ifndef _GAME_HPP_
#define _GAME_HPP_

//C++ Basics
#include <pthread.h>
#include <string>
#include <iostream>
#include <vector>
///////SDL2 Libs//////////////////
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
///////CORE LIBS////////////
#include "GameObject.hpp"
///////////////////////////

class Game
{
	public:

		Game();
		~Game();
		void Init(std::string winName,int win_x,int win_y,int win_width,int win_height);
		void HandleEvents();
		void Update();
		void Render();
		void Cleanup();
		bool isRunning();
		void setRunning(bool);

	private:
		std::string windowName;
		bool running;																//Holds game running state
		SDL_Window* mainWindow = nullptr;
		SDL_Renderer* mainRenderer = nullptr;
		std::vector<GameObject*> Objects;

};
#endif //_GAME_HPP_
