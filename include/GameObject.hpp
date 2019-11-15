#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_


#include <SDL2/SDL.h>

class GameObject
{
	private:
		bool alive;
		bool renderable;

	public:

		SDL_Rect Obj_Rect;
		virtual ~GameObject(){}
		virtual void update()=0;
		virtual void draw(SDL_Renderer* render)=0;
};
#endif
