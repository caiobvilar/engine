/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// *	Author: Caio Jose Borba Vilar Guimaraes
// *	Description: main class to all entities describing basic attributes, methods and basic design patterns as Update and Observer/Subject
// *	License: GLP 3.0
// *	Filename: GameEntity.hpp
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GAMEENTITY_HPP_
#define _GAMEENTITY_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

class GameEntity
{
	private:

		bool alive;
		double pos_x;
		double pos_y;

	public:
		
		GameEntity()
		{
			this->pos_x = 0;
			this->pos_y = 0;
		}
		virtual ~GameEntity(){}

		virtual void update();

		double getX(){return this->pos_x;}

		double getY(){return this->pos_y;}

		void setY(double new_y){this->pos_y = new_y;}

		void setX(double new_x){this->pos_x = new_x;}

		bool getIsAlive(){return this->alive;}

		void setIsAlive(bool status){this->alive = status;}

		virtual void onNotify(SDL_Event event);
};

#endif //_GAMEENTITY_HPP_
