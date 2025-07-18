/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GPL 3.0
//	Filename: application.cpp
/////////////////////////////////////////////////////////////////
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

void processEvents(SDL_Event& event, bool& is_done, SDL_Window* window)
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
                SDL_HideWindow(window);
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
    // Start ImGui frame
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Create right-side window
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(viewport->WorkPos.x +
                                           viewport->WorkSize.x -
                                           (viewport->WorkSize.x * 0.1f),
                                       viewport->WorkPos.y));
        ImGui::SetNextWindowSize(
            ImVec2(viewport->WorkSize.x * 0.1f, viewport->WorkSize.y));
        ImGui::Begin("Right Panel",
                     nullptr,
                     ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                         ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Right Side Panel");
        // Add your controls here

        ImGui::End();
    }
    // Rendering
    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        spdlog::info("Arguments: ");
        for (int i = 0; i < argc; i++)
        {
            spdlog::info("{}", argv[i]);
        }
    }
    spdlog::set_level(spdlog::level::info);
    spdlog::info("Starting application");
    uint32_t frameStart, frameTime;

    bool is_done = false;
    SDL_Window* window = createWindow();
    if (!window)
    {
        spdlog::error("Failed to create window");
        return -1;
    }
    SDL_Renderer* renderer = createRenderer(window);
    if (!renderer)
    {
        spdlog::error("Failed to create renderer");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    createImGuiContext(window, renderer);
    if (!ImGui::GetCurrentContext())
    {
        spdlog::error("Failed to create ImGui context");
        cleanup(window, renderer);
        return -1;
    }
    spdlog::info("ImGui context created successfully");

    while (!is_done)
    {
        frameStart = SDL_GetTicks();
        SDL_Event event;
        processEvents(event, is_done, window);
        if (is_done)
        {
            break;
        }
        Draw(renderer);

        // Here you would typically call your game update and render functions
        // For example:
        // Game->Update();
        // Game->Render();
        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime)
        {
            SDL_Delay((int)(FRAME_DELAY - frameTime));
        }
    }
    cleanup(window, renderer);
    spdlog::info("Application finished");
    spdlog::info("Exiting application");

    return 0;
}
