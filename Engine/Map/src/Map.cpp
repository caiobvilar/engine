#include "Map.hpp"

Map::Map() : mapWidth(0), mapHeight(0) {}
Map::~Map() {}
bool Map::LoadMap(const std::string& mapFilePath)
{
    this->configManager = ConfigurationManager::getInstance("config/map.json");
    this->tileAtlasManager = TileAtlasManager::getInstance();
    this->mapWidth = this->configManager.configData["map_width"];
    this->mapHeight = this->configManager.configData["map_height"];

    return true;
}

void Map::UnloadMap()
{
    // Implementation for unloading the map
}

void Map::Draw(SDL_Renderer* renderer)
{
    // Iterate through all rows and columns
    for (int row = 0; row < mapHeight; row++)
    {
        for (int col = 0; col < mapWidth; col++)
        {
            this->
                // Draw the tile
                SDL_RenderTexture(renderer, texture, &srcRect, &destRect);
        }
    }
}