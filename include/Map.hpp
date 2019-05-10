#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <cstddef>
#include <string>
class Map
{
	private:
		int *array;
		int map_rows;
		int map_columns;
		void LoadMap(std::string map_path, std::string texture_path);
		Map(int rows,int columns,std::string map_path,std::string texture_path);

	public:
		~Map();
		void update();
		size_t index(int row,int column);

};


#endif
