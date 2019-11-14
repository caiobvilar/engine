#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <cstddef>
#include <string>
#include <fstream>


class Map
{
	private:
		
		Sprite *tileSprite;
		std::array<SDL_Texture*,12> mapArray;

	public:
				
		Map(std::string Maptxt);
		~Map();
		void update();
		void loadMap(std::string Maptxt);
};


#endif
