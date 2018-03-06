#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

class GameObject
{
	public:
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;
	protected:
		GameObject();
		virtual ~GameObject();
		SDL_Rect domain;					// Reduces need for other objects and variable
															// Single variable to hold the objects size and position
};
#endif //_GAMEOBJECT_HPP_
