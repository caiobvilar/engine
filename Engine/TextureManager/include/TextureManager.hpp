#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>
#include <string>
#include <unordered_map>

class TextureManager
{
  public:
    static TextureManager& getInstance();
    SDL_Texture* LoadTexture(const std::string& filePath,
                             SDL_Renderer* renderer);
    void UnloadTexture(const std::string& filePath);
    void Clear();

  private:
    TextureManager() {}
    ~TextureManager() { Clear(); }
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    static TextureManager* instance;
    std::unordered_map<std::string, SDL_Texture*> textureCache;
    std::hash<std::string> hasher;
};

#endif // TEXTUREMANAGER_HPP