#ifndef MAP_HPP
#define MAP_HPP

#include <ConfigurationManager.hpp>
#include <SDL3/SDL.h>
#include <map>
#include <string>
#include <vector>

class Map
{
  public:
    Map();
    ~Map();

    bool LoadMap(const std::string& mapFilePath);
    void UnloadMap();
    void Draw(SDL_Renderer* renderer);

  private:
    std::map<std::string, SDL_Texture*> textures;
    std::vector<SDL_Rect> mapTiles;
    int mapWidth;
    int mapHeight;
};
#endif // MAP_HPP