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

class InputManager
{
	private:
		//There's no explicit Quit Queue, but everyone will be notified of quit event.
		std::queue<SDL_Event> InputQueue;
		std::list<GameEntity*> WindowGameEntitys;
		std::list<GameEntity*> KeyboardGameEntitys;
		std::list<GameEntity*> MouseMotionGameEntitys;
		std::list<GameEntity*> MouseButtonGameEntitys;
		std::list<GameEntity*> MouseWheelGameEntitys;
		//////////////Lists Respective Iterators////////////////////////////////////////
		std::list<GameEntity*>::iterator WindowGameEntitysITR;
		std::list<GameEntity*>::iterator KeyboardGameEntitysITR;
		std::list<GameEntity*>::iterator MouseMotionGameEntitysITR;
		std::list<GameEntity*>::iterator MouseButtonGameEntitysITR;
		std::list<GameEntity*>::iterator MouseWheelGameEntitysITR;

	public:

		InputHandler();  				//Initializes InputHandler.
		~InputHandler(); 				//Shutdown and Cleanup InputHandler.
		void pollInputEvents(); //Polls Event Queue for events to handle.
		void handleInputs();  	//Notifies whoever is interested about the events.
		void configure(); 			//Configures Input definitions etc.
		void attachGameEntity(enum InputType, GameEntity* observer);	//Attach GameEntity to some kind of event
		void detachGameEntity(enum InputType, GameEntity* observer); //Dettach GameEntity to event notifying list.
		void Init();       			//Start the module.
};

#endif //_INPUTHANDLER_HPP_
