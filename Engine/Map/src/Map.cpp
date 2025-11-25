#include "Map.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

Map::Map() : mapWidth(0), mapHeight(0)
{
}

Map::~Map()
{
    UnloadMap();
}

bool
Map::LoadMap(const std::string& mapFilePath)
{
    // Load the map JSON file
    std::ifstream mapFile(mapFilePath);
    if (!mapFile.is_open())
    {
        spdlog::error("Failed to open map file: {}", mapFilePath);
        return false;
    }

    nlohmann::json mapData;
    try
    {
        mapFile >> mapData;
    }
    catch (const nlohmann::json::parse_error& e)
    {
        spdlog::error("Failed to parse map file: {}", e.what());
        return false;
    }

    // Load map dimensions
    if (mapData.contains("map_width") && mapData["map_width"].is_number_integer())
    {
        this->mapWidth = mapData["map_width"];
    }
    else
    {
        spdlog::error("map_width not found or invalid in map file");
        return false;
    }

    if (mapData.contains("map_height") && mapData["map_height"].is_number_integer())
    {
        this->mapHeight = mapData["map_height"];
    }
    else
    {
        spdlog::error("map_height not found or invalid in map file");
        return false;
    }

    spdlog::info("Map loaded: {}x{}", this->mapWidth, this->mapHeight);
    // TODO: Implement tileset loading
    // for (auto& tileset : mapData["tilesets"])
    // {
    // }

    return true;
}

void
Map::UnloadMap()
{
    spdlog::debug("Unloading map resources");
    textures.clear();
    mapWidth = 0;
    mapHeight = 0;
}

void
Map::Draw(SDL_Renderer* renderer)
{
    (void)renderer; // Suppress unused parameter warning
    // TODO: Implement map drawing
    // Iterate through all rows and columns
    // for (int row = 0; row < mapHeight; row++)
    // {
    //     for (int col = 0; col < mapWidth; col++)
    //     {
    //         // Draw the tile
    //         SDL_RenderTexture(renderer, texture, &srcRect, &destRect);
    //     }
    // }
}