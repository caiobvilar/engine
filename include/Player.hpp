#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "GameObject.hpp"
#include "TextureManager.hpp"

class Player: public GameObject
{
	public:
		Player(const char* texturefile,SDL_Renderer* render, int x_start, int y_start);
		~Player();
		void update();
		void draw(SDL_Renderer *render);
		void setTexture(const char* filename, SDL_Renderer* render);
		int state_cntr = 0;
	private:
		SDL_Texture* player_sprsheet=nullptr;
};






#endif //_PLAYER_HPP_
