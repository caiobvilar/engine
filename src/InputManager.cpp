#include "../include/InputManager.hpp"

InputManager::InputManager()
{
	//Start Keyboard Event Queue
	this->registerNewQueue("Keyboard");
	this->registerNewQueue("Mouse");

	//Start Mouse Event Queue
	
}

InputManager::~InputManager()
{
}

void InputManager::registerNewQueue(SDL_Event*)
{
}

void InputManager::registerNewQueue(std::string queue_id)
{
	std::queue<SDL_Event*> event_queue;
	this->InputEventQueues.insert(
			std::pair<std::queue<SDL_Event*>,std::string>());
}

void InputManager::attachObserver(GameObject*)
{
}

void InputManager::dettachObserver(GameObject*)
{
}

void InputManager::dispatchEvents()
{
}
