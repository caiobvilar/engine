/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main application executable that runs all game structures
//	License: GPL 3.0
//	Filename: Application.cpp
/////////////////////////////////////////////////////////////////

#include "engine.hpp"
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
        processEvents(event, is_done);
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
        spdlog::info("Frame time: {} ms", frameTime);
    }
    cleanup(window, renderer);
    spdlog::info("Application finished");
    spdlog::info("Exiting application");

    return 0;
}