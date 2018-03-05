#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <pthread.h>
#include <map>
#include <vector>
#include <algorithm>

class InputManager
{
	private:
		bool isRunning;
		//Map of lists for input event observers: text input, text edit, mousemotion,
		//mousebutton, mousewheel, joystick_axis, etc. Comming from
		//Keyboard, controller, joystick or mouse
		std::map<std::queue,std::string> InputEventQueue;
	public:
		InputManager();
		~InputManager();
		void attachObserver(Observer *nosyClass);
		void dettachObserver(Observer *nosyClass);
		void dispatchEvents(std::vector<Observer*> ObsList);
}

#endif //_INPUTMANAGER_HPP_
