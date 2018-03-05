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
};
#endif //_GAMEOBJECT_HPP_
