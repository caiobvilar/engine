#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "ConfigurationManager.hpp"
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

#define FPS 60.0f
#define FRAME_DELAY (1000.0f / FPS) // Frame delay in milliseconds
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class Engine
{
  public:
    Engine();
    ~Engine();
    void Run();
    float GetFPS();

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
    SDL_Keycode exitKey;

    int CreateWindow();
    int CreateRenderer();
    void Cleanup();
    void ProcessEvents();
    int Draw();
    void Update();
};

#endif // ENGINE_HPP