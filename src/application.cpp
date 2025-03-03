/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GPL 3.0
//	Filename: application.cpp
/////////////////////////////////////////////////////////////////
#include "imgui.h"
#include <SDL2/SDL.h>
#include <imgui_impl_sdl2.h>
#include <iostream>
#include <spdlog/spdlog.h>

#define FPS 60
#define FRAME_DELAY 1000 / FPS

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
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::error("Error initializing SDL: {}", SDL_GetError());
        return -1;
    }
    SDL_Window* window = SDL_CreateWindow("Main Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1024,
                                          780,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        spdlog::error("Error creating window: {}", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        spdlog::error("Error creating renderer: {}", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    bool is_done = false;

    while (!is_done)
    {
        frameStart = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
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
            // GameInstance->Update();
            // GameInstance->Render();
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);

            frameTime = SDL_GetTicks() - frameStart;
            if (FRAME_DELAY > frameTime)
            {
                SDL_Delay((int)(FRAME_DELAY - frameTime));
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
