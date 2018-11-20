#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

class GameObject
{
	private:
		int speed;
		int x_pos,y_pos;
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
		void setSpeed(int spd) {this->speed = spd;}
		int getSpeed() {return this->speed;}
}

#endif
