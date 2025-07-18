
#include "imgui.h"
#include <SDL2/SDL.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h> // Add this include
#include <iostream>
#include <spdlog/spdlog.h>

#define FPS 60
#define FRAME_DELAY 1000 / FPS
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
void createImGuiContext(SDL_Window* window, SDL_Renderer* renderer);
void cleanup(SDL_Window* window, SDL_Renderer* renderer);
void processEvents(SDL_Event& event, bool& is_done);
void Draw(SDL_Renderer* renderer);