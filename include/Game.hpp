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

#include "../include/GameObject.hpp"
#include "../include/WindowModule.hpp"
#include "../include/InputManager.hpp"
//#include "../include/AudioModule.hpp"
///////////////////////////

class Game
{
	public:

		Game();
		~Game();

		void Init();
		void Update(); 															//Update Status of all gameObjects
		void Render(); 															//Render all gameobjects on the window surface
		void HandleEvents();												//handle non-input events
		void Clean(); 															//Garbage Collection
		bool isRunning();														//Returns if game is still running
		void RegisterGObject(GameObject *GObject);	//Registers new GameObject on the list

	private:

		bool running;																//Holds game running state
		std::vector<GameObject*> GameObjects;				//Holds a vector with all the game objects
		WindowModule *mainWindow;
		InputManager *inputManager;
		//AudioModule *audioModule;
		//MapModule
		//FileManager
		//LogModule
		//etc
};
#endif //_GAME_HPP_
