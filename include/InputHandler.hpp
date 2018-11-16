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
		std::list<GameEntity*> WindowObservers;
		std::list<GameEntity*> KeyboardObservers;
		std::list<GameEntity*> MouseMotionObservers;
		std::list<GameEntity*> MouseButtonObservers;
		std::list<GameEntity*> MouseWheelObservers;
		//////////////Lists Respective Iterators////////////////////////////////////////
		std::list<GameEntity*>::iterator WindowObserversITR;
		std::list<GameEntity*>::iterator KeyboardObserversITR;
		std::list<GameEntity*>::iterator MouseMotionObserversITR;
		std::list<GameEntity*>::iterator MouseButtonObserversITR;
		std::list<GameEntity*>::iterator MouseWheelObserversITR;

	public:

		InputHandler();  				//Initializes InputHandler.
		~InputHandler(); 				//Shutdown and Cleanup InputHandler.
		void pollInputEvents(); //Polls Event Queue for events to handle.
		void handleInputs();  	//Notifies whoever is interested about the events.
		void configure(); 			//Configures Input definitions etc.
		void attachObserver(enum InputType, GameEntity* observer);	//Attach GameEntity to some kind of event
		void detachObserver(enum InputType, GameEntity* observer); //Dettach GameEntity to event notifying list.
		void Init();       			//Start the module.
};

#endif //_INPUTHANDLER_HPP_
