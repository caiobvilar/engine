#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include "GameObject.hpp"

class Player : public GameObject
{
	public:
		void draw();
		void update();
		void clean();

};

#endif //_PLAYER_HPP_
