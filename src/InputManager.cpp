#include "../include/InputManager.hpp"
#include <iostream>

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

int InputManager::init()
{
	//Start Keyboard Event Queue
	this->registerNewQueue("Keyboard");
	std::cout << "[SYSTEM]: started Keyboard event queue." << std::endl;
	//Start Mouse Event Queue
	this->registerNewQueue("Mouse");
	std::cout << "[SYSTEM]: started Mouse event queue." << std::endl;
	return 0;
}

void InputManager::configure()
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

void InputManager::addNewEvent(SDL_Event *event, std::string queue_id)
{
	this->
}
void InputManager::attachObserver(GameObject*,std::string id_queue)
{
	this->InputObservers.insert(std::pair<>())
}

void InputManager::dettachObserver(GameObject*)
{
}

void InputManager::dispatchEvents()
{
}
