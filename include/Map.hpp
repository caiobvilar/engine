#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <cstddef>
#include <string>
class Map
{
	private:
		
		void LoadMap(std::string map_path, std::string texture_path);
	public:
		
		Map();
		~Map();
		void update();

};


#endif
