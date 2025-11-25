#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP
#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>
#include <vector>

enum MouseButtons
{
    LEFT_BUTTON = 0,
    MIDDLE_BUTTON = 1,
    RIGHT_BUTTON = 2
};

class InputManager
{
  public:
    // Singleton access method
    static InputManager&
    getInstance();
    // Process a single SDL event
    void
    ProcessEvent(const SDL_Event* event);
    // Update input states (call once per frame)
    void
    Update();
    // Cleanup resources
    void
    Cleanup();
    // Initialize Joysticks
    void
    InitializeJoysticks();
    bool
    JoysticksInitialized();

  private:
    static InputManager* instance;
    bool joysticksInitialized = false;
    std::vector<SDL_Joystick*> joysticks;
    std::vector<bool> mouseButtonStates;
};
#endif // INPUTMANAGER_HPP