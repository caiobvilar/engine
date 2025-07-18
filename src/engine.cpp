/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GPL 3.0
//	Filename: engine.cpp
/////////////////////////////////////////////////////////////////
#include "engine.hpp"
SDL_Window* createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::error("Error initializing SDL: {}", SDL_GetError());
        return nullptr;
    }
    SDL_Window* window = SDL_CreateWindow("Main Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        spdlog::error("Error creating window: {}", SDL_GetError());
        SDL_Quit();
        return nullptr;
    } else
    {
        spdlog::info("Window created successfully");
        return window;
    }
}
SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        spdlog::error("Error creating renderer: {}", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return nullptr;
    } else
    {
        spdlog::info("Renderer created successfully");
        return renderer;
    }
}
void createImGuiContext(SDL_Window* window, SDL_Renderer* renderer)
{
    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer); // Add this line
    ImGui::StyleColorsDark();
}
void cleanup(SDL_Window* window, SDL_Renderer* renderer)
{
    // Cleanup
    ImGui_ImplSDLRenderer2_Shutdown(); // Add this line
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void processEvents(SDL_Event& event, bool& is_done)
{
    // Handle events
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event); // Add this to handle ImGui events

        if (event.type == SDL_QUIT)
        {
            is_done = true;
        }
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
                is_done = true;
                break;
            default:
                break;
            }
        }
        if (event.type == SDL_WINDOWEVENT)
        {
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                spdlog::debug("Window [{}] closed", event.window.windowID);
                break;
            default:
                break;
            }
        }
    }
}

void Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
