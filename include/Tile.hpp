#ifndef _TILE_HPP_
#define _TILE_HPP_

#include "GameObject"

class Tile : public GameObject
{
	public:

		bool isPassable();
	
	private:

};

#endif //_TILE_HPP_
//TODO: model the rest of the data
//methods and variables this class needs
//also tie its configuration and behaviour
//with a texture managre, like pulling
//textures from a pool to reduce memkory allocation
//unnecessarily, the main idea is to keep
//a big pool of reusable data on memory to make
//acessibility and reusability faster and seamless state transitions.
