#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

//Classes that derive from GameObject:
//
//Player
//Mob
//Prop
//

class GameObject
{
	private:
		SDL_Rect Obj_Rect;
		bool alive;
		bool renderable;

	public:

		virtual ~GameObject() {}
		virtual void update();
		bool isRenderable() {return this->renderable;}
		bool isAlive() {return this->isAlive;}
		void setX(int x) {this->x_pos = x;}
		void setY(int y) {this->y_pos = y;}
		int getX() {return this->x_pos;}
		int getY() {return this->y_pos;}
}

#endif
