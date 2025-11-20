#ifndef MAP_HPP
#define MAP_HPP

#include <ConfigurationManager.hpp>
#include <SDL3/SDL.h>
#include <TileAtlasManager.hpp>
#include <map>
#include <spdlog/spdlog.h>
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
    ConfigurationManager& configManager = nullptr;
    TileAtlasManager& tileAtlasManager = nullptr;
    std::map<std::string, std::string> textures;
    int mapWidth;
    int mapHeight;
};
#endif // MAP_HPP