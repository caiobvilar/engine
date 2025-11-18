#include "Map.hpp"

Map::Map() : mapWidth(0), mapHeight(0) {}
Map::~Map() {}
bool Map::LoadMap(const std::string& mapFilePath)
{
    // Implementation for loading a map from a file
    // TODO: Parse JSON from mapFilePath and populate mapTiles, textures, etc.
    (void)mapFilePath; // Suppress unused parameter warning for now
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
            // Calculate tile index in the flat array
            int tileIndex = row * mapWidth + col;

            if (tileIndex >= static_cast<int>(mapTiles.size()))
                continue; // Safety check

            SDL_Rect& tile = mapTiles[tileIndex];
            SDL_Texture* texture =
                textures["tileset"]; // Get your loaded texture

            // Source rect (which tile from the tileset to use)
            SDL_FRect srcRect = {
                (float)tile.x, // Tile X position in tileset
                (float)tile.y, // Tile Y position in tileset
                (float)tile.w, // Tile width
                (float)tile.h  // Tile height
            };

            // Destination rect (where to draw on screen)
            SDL_FRect destRect = {
                (float)(col * tile.w), // Screen X = column * tile width
                (float)(row * tile.h), // Screen Y = row * tile height
                (float)tile.w,         // Width on screen
                (float)tile.h          // Height on screen
            };

            // Draw the tile
            SDL_RenderTexture(renderer, texture, &srcRect, &destRect);
        }
    }
}