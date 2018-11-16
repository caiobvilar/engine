#include "../include/InputHandler.hpp"

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
				for(this->WindowObserversITR = this->WindowObservers.begin();
						this->WindowObserversITR != this->WindowObservers.end();
						this->WindowObserversITR++)
				{
					(*this->WindowObserversITR)->onNotify(this->InputQueue.front());
				}
				this->InputQueue.pop();
				break;
			case SDL_KeyboardEvent:
				for(this->KeyboardObserversITR = this->KeyboardObservers.begin();
						this->KeyboardObserversITR != this->KeyboardObservers.end();
						this->KeyboardObserversITR++)
				{
					(*this->KeyboardObserversITR)->onNotify(this->InputQueue.front());
				}
				this->InputQueue.pop();
				break;
			case SDL_MouseMotionEvent:
				//notify
				this->InputQueue.pop();
				break;
			case SDL_MouseButtonEvent:
				//notify
				this->InputQueue.pop();
				break;
			case SDL_MouseWheelEvent:
				//notify
				this->InputQueue.pop();
				break;
			case SDL_QuitEvent:
				//notify
				for(this->WindowObserversITR = this->WindowObservers.begin();
						this->WindowObserversITR != this->WindowObservers.end();
						this->WindowObserversITR++)
				{
					(*this->WindowObserversITR)->onNotify(this->InputQueue.front());
				}
				for(this->KeyboardObserversITR = this->KeyboardObservers.begin();
						this->KeyboardObserversITR != this->KeyboardObservers.end();
						this->KeyboardObserversITR++)
				{
					(*this->KeyboardObserversITR)->onNotify(this->InputQueue.front());
				}
				this->InputQueue.pop();
				break;
		}
	}
}

void InputHandler::attachObserver(InputType ObsType, GameEntity* observer)
{
	switch(ObsType)
	{
		case Window:
			this->WindowObservers.push_front(observer);
			break;
		case Keyboard:
			this->KeyboardObservers.push_front(observer);
			break;
		case MouseMotion:
			this->MouseMotionObservers.push_front(observer);
			break;
		case MouseButton:
			this->MouseButtonObservers.push_front(observer);
			break;
		case MouseWheel:
			this->MouseWheelObservers.push_front(observer);
			break;
	}
}


void InputHandler::detachObserver(InputType ObsType, GameEntity* observer)
{
	static std::list<GameEntity*>::iterator detachITR;

	switch(ObsType)
	{
		case Window:
			detachITR = std::find(this->WindowObservers.begin(),this->WindowObservers.end(),observer);
			this->WindowObservers.erase(detachITR);
			break;
		case Keyboard:
			detachITR = std::find(this->KeyboardObservers.begin(),this->KeyboardObservers.end(),observer);
			this->KeyboardObservers.erase(detachITR);
			break;
		case MouseMotion:
			detachITR = std::find(this->MouseMotionObservers.begin(),this->MouseMotionObservers.end(),observer);
			this->MouseMotionObservers.erase(detachITR);
			break;
		case MouseButton:
			detachITR = std::find(this->MouseButtonObservers.begin(),this->MouseButtonObservers.end(),observer);
			this->MouseButtonObservers.erase(detachITR);
			break;
		case MouseWheel:
			detachITR = std::find(this->MouseWheelObservers.begin(),this->MouseWheelObservers.end(),observer);
			this->MouseWheelObservers.erase(detachITR);
			break;
	}

}













