/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main executable that runs all modules and game
//	License: GPL 3.0
//	Filename: engine.cpp
/////////////////////////////////////////////////////////////////

#include "engine.hpp"

Engine::Engine()
{
    this->is_done = false;
    this->imguiInitialized = false;
    this->currentTime = static_cast<decltype(this->currentTime)>(SDL_GetTicks());
    this->lastTime = this->currentTime;
    this->timeStep = 0.0f;

    // Load configuration file
    spdlog::info("Initializing ConfigurationManager...");
    this->configManager = &ConfigurationManager::getInstance();
    if (this->configManager->loadConfig("/workspace/Application/config/config.json") != 0)
    {
        spdlog::error("Failed to load /workspace/Application/config/config.json, using "
                      "defaults");
    }

    // Calculate target frame delay from configured FPS
    this->fps = this->configManager->GetDefaultFPS();
    this->targetFrameDelay = 1000.0f / this->fps;
    spdlog::info("Target FPS: {}, Frame delay: {:.2f}ms", this->fps, this->targetFrameDelay);

    // Read and store exit key from configuration
    char exitChar = this->configManager->GetDefaultExitChar();
    this->exitKey = SDL_GetKeyFromName(&exitChar);
    spdlog::info("Exit key configured as: '{}'", exitChar);

    if (this->CreateWindow() != 0)
    {
        spdlog::error("Failed to create window");
        this->is_done = true;
        return;
    }
    if (this->CreateRenderer() != 0)
    {
        spdlog::error("Failed to create renderer");
        this->is_done = true;
        return;
    }
    // Initialize Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);
    this->imguiInitialized = true;

    // Load the map
    this->map.LoadMap("/workspace/Application/config/map.json");
    // Start Input Manager Joysticks
    InputManager::getInstance().InitializeJoysticks();
}

Engine::~Engine()
{
    this->Cleanup();
}

SDL_Renderer*
Engine::GetRenderer() const
{
    return this->renderer;
}

SDL_Window*
Engine::GetWindow() const
{
    return this->window;
}

Map&
Engine::GetMap()
{
    return this->map;
}

void
Engine::Run()
{
    while (!this->is_done)
    {
        uint64_t frameStart = static_cast<decltype(frameStart)>(SDL_GetTicks());

        this->currentTime = frameStart;
        this->timeStep = (this->currentTime - this->lastTime) / 1000.0f; // in seconds
        this->lastTime = this->currentTime;

        this->ProcessEvents();
        this->Update();
        this->Draw();
        // Cap the frame rate based on configured FPS
        uint64_t frameEnd = static_cast<decltype(frameEnd)>(SDL_GetTicks());
        uint64_t frameTime = frameEnd - frameStart;

        if (frameTime < static_cast<uint64_t>(this->targetFrameDelay))
        {
            SDL_Delay(static_cast<uint32_t>(this->targetFrameDelay - frameTime));
        }
    }
}

int
Engine::CreateWindow()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        spdlog::error("Error initializing SDL: {}", SDL_GetError());
        return -1;
    }
    SDL_Window* window = SDL_CreateWindow("Main Window", this->configManager->GetWindowWidth(),
                                          this->configManager->GetWindowHeight(), SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        spdlog::error("Error creating window: {}", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    else
    {
        spdlog::info("Window created successfully");
        this->window = window;
    }
    return 0;
}

int
Engine::CreateRenderer()
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        spdlog::error("Error creating renderer: {}", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    else
    {
        spdlog::info("Renderer created successfully");
        this->renderer = renderer;
        return 0;
    }
}

void
Engine::Cleanup()
{
    spdlog::info("Starting engine cleanup...");

    // Unload map resources
    spdlog::debug("Unloading map resources");
    this->map.UnloadMap();

    // Clear texture cache
    spdlog::debug("Clearing texture manager cache");
    TextureManager::getInstance().Clear();

    // Cleanup ImGui (only if it was successfully initialized)
    if (this->imguiInitialized)
    {
        spdlog::debug("Shutting down ImGui");
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
    }

    // Cleanup SDL resources
    if (this->renderer != nullptr)
    {
        spdlog::debug("Destroying SDL renderer");
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }
    if (this->window != nullptr)
    {
        spdlog::debug("Destroying SDL window");
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
    delete this->configManager;
    this->configManager = nullptr;
    InputManager::getInstance().Cleanup();


    spdlog::debug("Quitting SDL");
    SDL_Quit();

    spdlog::info("Engine cleanup completed");
}

void
Engine::ProcessEvents()
{
    while (SDL_PollEvent(&this->event))
    {
        // Let ImGui handle the event first
        ImGui_ImplSDL3_ProcessEvent(&this->event);

        // Let InputManager process the event
        InputManager::getInstance().ProcessEvent(&this->event);

        // Handle engine-level events
        switch (this->event.type)
        {
        case SDL_EVENT_QUIT:
            this->is_done = true;
            break;
        case SDL_EVENT_KEY_DOWN:
            // Check if the pressed key matches the configured exit key
            if (this->event.key.key == this->exitKey)
            {
                spdlog::info("Exit key pressed");
                this->is_done = true;
            }
            break;
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            spdlog::debug("Window close requested");
            this->is_done = true;
            break;
        default:
            break;
        }
    }

    // Update input manager state after all events processed
    InputManager::getInstance().Update();
}

int
Engine::Draw()
{
    if (this->renderer == nullptr)
    {
        spdlog::error("Renderer is null in Draw function");
        return -1;
    }
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    // Note: SDL_RenderPresent is now called in Application.cpp after ImGui
    // rendering

    // Start ImGui frame
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    // Create FPS HUD
    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(200, 80), ImGuiCond_FirstUseEver);
    ImGui::Begin("Performance", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    float currentFPS = this->GetFPS();
    ImGui::Text("FPS: %.1f", currentFPS);
    ImGui::Text("Frame Time: %.3f ms", this->timeStep * 1000.0f);
    ImGui::End();

    this->Update();

    // Render ImGui
    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), this->renderer);

    SDL_RenderPresent(this->renderer);
    return 0;
}

void
Engine::Update()
{
    spdlog::debug("Updating game logic with time step: {:.6f} seconds", this->timeStep);
}

float
Engine::GetFPS()
{
    if (this->timeStep > 0.0f)
    {
        return 1.0f / this->timeStep;
    }
    return 0.0f;
}