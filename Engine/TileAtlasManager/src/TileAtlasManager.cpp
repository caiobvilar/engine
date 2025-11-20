#include "TileAtlasManager.hpp"

TileAtlasManager& TileAtlasManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new TileAtlasManager();
    }
    return *instance;
}

void TileAtlasManager::LoadTileAtlas(const std::string& atlasFilePath,
                                     SDL_Renderer* renderer)
{
    auto texture =
        TextureManager::getInstance().LoadTexture(atlasFilePath, renderer);
    if (texture == nullptr)
    {
        spdlog::error("Failed to load tile atlas from '{}'", atlasFilePath);
        return;
    }

    // Store the texture in the cache with its name from the file hashed as the
    // key

    spdlog::info("Tile atlas '{}' loaded successfully", atlasFilePath);
}

std::shared_ptr<SDL_Texture>
TileAtlasManager::GetTileTexture(std::shared_ptr<Tile> tile,
                                 SDL_Renderer* renderer)
{
    auto it = atlasCache.find(tile);
    if (it != atlasCache.end())
    {
        spdlog::debug("Tile texture loaded from cache");
        return it->second;
    }
    return std::shared_ptr<SDL_Texture>();
}
