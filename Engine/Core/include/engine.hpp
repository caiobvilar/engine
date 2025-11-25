#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "ConfigurationManager.hpp"
#include "InputManager.hpp"
#include "Map.hpp"
#include "Math.hpp"
#include "TextureManager.hpp"
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

struct State
{
    Vec2D pos; // This seems redundant but keeps things clear
    Vec2D vel; // Same as above
    Vec2D acc; // and allows for me to use other math libraries later
    // and allows for me to use other math libraries later
};

struct Velocity
{
};

class Engine
{
  public:
    Engine();
    ~Engine();
    void
    Run();
    float
    GetFPS();
    SDL_Renderer*
    GetRenderer() const;
    SDL_Window*
    GetWindow() const;
    Map&
    GetMap();

  private:
    entt::registry registry;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    ConfigurationManager* configManager = nullptr;
    bool is_done;
    uint64_t currentTime = 0;
    uint64_t lastTime = 0;
    float timeStep = 0.0f;
    SDL_Event event;
    float fps = 0.0f;
    float targetFrameDelay = 0.0f; // Calculated from configured FPS
    SDL_Keycode exitKey;
    bool imguiInitialized = false;
    Map map;

    int
    CreateWindow();
    int
    CreateRenderer();
    void
    Cleanup();
    void
    ProcessEvents();
    int
    Draw();
    void
    Update();
};

#endif // ENGINE_HPP