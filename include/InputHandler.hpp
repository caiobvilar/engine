#ifndef _INPUTHANDLER_HPP_
#define _INPUTHANDLER_HPP_

#include <pthread.h>
#include <queue>
#include <list>
#include <algorithm>
#include <SDL2/SDL.h>
#include <utility>
#include "GameEntity.hpp"

enum InputType {Window, Keyboard, MouseMotion, MouseButton, MouseWheel,Quit};

class InputHandler
{
	private:
		//There's no explicit Quit Queue, but everyone will be notified of quit event.
		std::queue<SDL_Event> InputQueue;
		bool running = false;
	public:

		InputHandler();  				//Initializes InputHandler.
		~InputHandler(); 				//Shutdown and Cleanup InputHandler.
		void pollInputEvents(); //Polls Event Queue for events to handle.
		void handleInputs();  	//Notifies whoever is interested about the events.
		void configure(); 			//Configures Input definitions etc.
		void notifyWindow(WindowModule* window);
};

#endif //_INPUTHANDLER_HPP_
