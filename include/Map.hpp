#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <cstddef>

class Map
{
	int *array;
	int map_rows;
	int map_columns;

	Map(int rows,int columns);
	~Map();
	size_t index(int row,int column);

};


#endif
