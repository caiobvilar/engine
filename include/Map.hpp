#ifndef _MAP_HPP_
#define _MAP_HPP_
#include "GameObject.hpp"
#include "MapChunk.hpp"

class Map : public GameObject
{
	public:
		void draw();
		void update();
		void clean();
	private:
		std::vector<MapChunk> MapChunks;

};

#endif //_MAP_HPP_
