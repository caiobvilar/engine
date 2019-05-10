#include "../include/Map.hpp"


Map::Map(int rows,int columns)
{
	this->array = new int[rows*columns];
	this->map_rows=rows;
	this->map_columns=columns;
}
Map::~Map()
{
	delete this->array;
	this->array = nullptr;
}

size_t Map::index(int row,int column)
{
	return (row+this->map_rows)*column;
}

void Map::Map(int rows,int columns,std::string map_path,std::string texture_path);
{

}

void Map::update()
{

}
