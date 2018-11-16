#include "../include/InputHandler.hpp"

InputHandler::InputHandler()
{
	this->running = true;
}

InputHandler::~InputHandler()
{
	this->WindowObservers.clear();
	this->KeyboardObservers.clear();
	this->MouseMotionObservers.clear();
	this->MouseButtonObservers.clear();
	this->MouseWheelObservers.clear();
	this->running = false;
}

void InputHandler::pollInputEvents()
{
	static SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		this->InputQueue.push(event);
	}
}

void InputHandler::configure()
{
	//Configures the inputhandler according to the input type
}

void InputHandler::handleInputs()
{
	//notifies observers of the respective subjected events;
	while(!this->InputQueue.empty())
	{
		switch(this->InputQueue.front().type)
		{
			case SDL_WINDOWEVENT:
				for()
				break;
			case SDL_KEYUP:
				break;
			case SDL_KEYDOWN:
				break;
			case SDL_QUIT:
				//notify
				break;
		}
	}
}
