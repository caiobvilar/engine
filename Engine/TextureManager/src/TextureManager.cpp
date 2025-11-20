#include "TextureManager.hpp"

TextureManager* TextureManager::instance = nullptr;

TextureManager& TextureManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new TextureManager();
    }
    return *instance;
}
SDL_Texture* TextureManager::LoadTexture(const std::string& filePath,
                                         SDL_Renderer* renderer)
{
    auto it = textureCache.find(filePath);
    if (it != textureCache.end())
    {
        spdlog::debug("Texture '{}' loaded from cache", filePath);
        return it->second;
    }

    SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
    if (surface == nullptr)
    {
        spdlog::error(
            "Failed to load BMP file '{}': {}", filePath, SDL_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    if (texture == nullptr)
    {
        spdlog::error("Failed to create texture from file '{}': {}",
                      filePath,
                      SDL_GetError());
        return nullptr;
    }

    textureCache[filePath] = texture;
    spdlog::info("Texture '{}' loaded successfully", filePath);
    return texture;
}
void TextureManager::UnloadTexture(const std::string& filePath)
{
    auto it = textureCache.find(filePath);
    if (it != textureCache.end())
    {
        SDL_DestroyTexture(it->second);
        textureCache.erase(it);
        spdlog::info("Texture '{}' unloaded", filePath);
    }
}
void TextureManager::Clear()
{
    for (auto& pair : textureCache)
    {
        SDL_DestroyTexture(pair.second);
    }
    textureCache.clear();
    spdlog::info("All textures cleared");
}