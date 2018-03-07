#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <pthread.h>
#include <map>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include "GameObject.hpp"

class InputManager
{
	private:

		bool isRunning;
		//Map of lists for input event observers: text input, text edit, mousemotion,
		//mousebutton, mousewheel, joystick_axis, etc. Comming from
		//Keyboard, controller, joystick or mouse

		std::map<std::queue<SDL_Event*>,std::string> InputEventQueue;
		std::map<std::queue<GameObjects>,std::string> InputObservers; //Game Objects that are listening for inputs.
	public:

		InputManager();
		~InputManager();
		void registerNewQueue(SDL_Event*);	//Gets an Event and sorts it out to create a new queue.If non-existant.
		void attachObserver(GameObject*);
		void dettachObserver(GameObject*);
		void dispatchEvents();
}

#endif //_INPUTMANAGER_HPP_
