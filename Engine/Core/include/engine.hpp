#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "ConfigurationManager.hpp"
#include "Map.hpp"
#include "imgui.h"
#include <SDL3/SDL.h>
#include <cassert>
#include <cstdint>
#include <entt/entt.hpp>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>
#include <vector>

class Engine
{
  public:
    Engine();
    ~Engine();
    void Run();
    float GetFPS();
    SDL_Renderer* GetRenderer() const { return renderer; }
    SDL_Window* GetWindow() const { return window; }
    Map& GetMap() { return map; }

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    ConfigurationManager& configManager =
        ConfigurationManager::getInstance("config.json");
    bool is_done;
    uint64_t currentTime;
    uint64_t lastTime;
    float timeStep;
    SDL_Event event;
    float fps;
    float targetFrameDelay; // Calculated from configured FPS
    SDL_Keycode exitKey;
    Map map;

    int CreateWindow();
    int CreateRenderer();
    void Cleanup();
    void ProcessEvents();
    int Draw();
    void Update();
};

#endif // ENGINE_HPP