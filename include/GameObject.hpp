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
		bool isAlive() {return this->alive;}
		void setX(int x) {this->Obj_Rect.x = x;}
		void setY(int y) {this->Obj_Rect.y = y;}
		int getX() {return this->Obj_Rect.x;}
		int getY() {return this->Obj_Rect.y;}
};
#endif
