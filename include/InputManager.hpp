#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <pthread.h>
#include <queue>
#include <map>
#include <algorithm>
#include <SDL2/SDL.h>
#include "GameObject.hpp"
#include <utility>

class InputManager
{
	private:

		bool isRunning;
		//Map of lists for input event observers: text input, text edit, mousemotion,
		//mousebutton, mousewheel, joystick_axis, etc. Comming from
		//Keyboard, controller, joystick or mouse

		std::map<std::queue<SDL_Event*>,std::string> InputEventQueues;
		std::map<std::queue<GameObject*>,std::string> InputObservers; //Game Objects that are listening for inputs.

	public:

		InputManager();
		~InputManager();
		void configure();
		int init();
		//@function: registerNewQueue()
		//@return: void
		//@arguments: SDL_Event*
		//@description: Gets an Event and sorts 
		//it out to create a new queue.If non-existant.
		void registerNewQueue(SDL_Event*);	
		void registerNewQueue(std::string);	 //Basic queue, like keyboard and mouse
		void attachObserver(GameObject*);
		void addNewEvent(SDL_Event *event, std::string queue_id);
		void dettachObserver(GameObject*);
		void dispatchEvents();
};

#endif //_INPUTMANAGER_HPP_
