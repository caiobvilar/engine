#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <cstddef>
#include <string>
class Map
{
	private:
		
		void LoadMap(std::string map_path, std::string texture_path);
		Map(int rows,int columns,std::string map_path);

	public:
		
		~Map();
		void update();

};


#endif
