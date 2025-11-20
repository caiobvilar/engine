#ifndef TILEATLASMANAGER_HPP
#define TILEATLASMANAGER_HPP

#include <ConfigurationManager.hpp>
#include <SDL3/SDL.h>
#include <TextureManager.hpp>
#include <memory>
#include <spdlog/spdlog.h>
#include <string>
#include <unordered_map>

struct Tile
{
    SDL_FRect srcRect; // Source rectangle in the atlas
    ssize_t tileHash;  // Unique identifier for the tile
};

class TileAtlasManager
{
  public:
    static TileAtlasManager& getInstance();
    void LoadTileAtlas(const std::string& atlasFilePath,
                       SDL_Renderer* renderer);
    std::shared_ptr<SDL_Texture> GetTileTexture(std::shared_ptr<Tile> tile,
                                                SDL_Renderer* renderer);

  private:
    TileAtlasManager() {}
    ~TileAtlasManager() {}
    TileAtlasManager(const TileAtlasManager&) = delete;
    TileAtlasManager& operator=(const TileAtlasManager&) = delete;

    static TileAtlasManager* instance;
    static ConfigurationManager& configManager;
    std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<SDL_Texture>>
        atlasCache;
};
#endif // TILEATLASMANAGER_HPP