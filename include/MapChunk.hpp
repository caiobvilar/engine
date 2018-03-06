#ifndef _MAPCHUNK_HPP_
#define _MAPCHUNK_HPP_

#include "GameObject.hpp"
#include "Tile.hpp"

class MapChunk : public GameObject
{
	public:

		void update();
		void clean();

	private:
		std::vector<Tile*> tileList;
		
}

#endif // _MAPCHUNK_HPP_
