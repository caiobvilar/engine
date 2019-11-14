#include "../include/Map.hpp"

Map::Map(std::string Maptxt)
{
	this->tileSprite = new Sprite();
	this->loadMap(Maptxt);
}

Map::~Map()
{
	delete this->tileSprite;
	this->tileSprite = nullptr;
}

void Map::loadMap(std::string Maptxt)
{
	std::ifstream file(Maptxt.c_str());
	int type=0;
	if(file.is_open())
	{
		for(int i=0;i<12;i++)
		{
			file >> type;
			switch(type)
			{
				case 0:
					this->array[i] = this->tileSprite.textureTree.find(0);
					break;
				case 1:
					this->array[i] = this->tileSprite.textureTree.find(1);
					break;

			}
		}
	}
	file.close();
}

void Map::update()
{

}
