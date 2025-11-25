#include "InputManager.hpp"

InputManager* InputManager::instance = nullptr;

InputManager&
InputManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new InputManager();
    }
    return *instance;
}

void
InputManager::ProcessEvent(const SDL_Event* event)
{
    if (event == nullptr)
    {
        return;
    }

    switch (event->type)
    {
    case SDL_EVENT_KEY_DOWN:
        spdlog::debug("Key down: {}", SDL_GetKeyName(event->key.keysym.sym));
        break;
    case SDL_EVENT_KEY_UP:
        spdlog::debug("Key up: {}", SDL_GetKeyName(event->key.keysym.sym));
        break;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
        spdlog::debug("Mouse button down: {}", event->button.button);
        if (SDL_MOUSEBUTTON_LEFT >= 0 && event->button.button < mouseButtonStates.size())
        {
            mouseButtonStates[LEFT_BUTTON] = true;
        }
        break;
    case SDL_EVENT_MOUSE_BUTTON_UP:
        spdlog::debug("Mouse button up: {}", event->button.button);
        if (event->button.button >= 0 && event->button.button < mouseButtonStates.size())
        {
            mouseButtonStates[event->button.button] = false;
        }
        break;
    case SDL_EVENT_MOUSE_MOTION:
        spdlog::debug("Mouse motion: x={}, y={}", event->motion.x, event->motion.y);
        break;
    case SDL_EVENT_JOYSTICK_ADDED:
        spdlog::debug("Joystick added: index {}", event->jdevice.which);
        break;
    case SDL_EVENT_JOYSTICK_REMOVED:
        spdlog::debug("Joystick removed: instance ID {}", event->jdevice.which);
        break;
    case SDL_EVENT_JOYSTICK_AXIS_MOTION:
        spdlog::debug("Joystick axis motion: axis {} value {}", event->jaxis.axis, event->jaxis.value);
        break;
    case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
        spdlog::debug("Joystick button down: button {}", event->jbutton.button);
        break;
    case SDL_EVENT_JOYSTICK_BUTTON_UP:
        spdlog::debug("Joystick button up: button {}", event->jbutton.button);
        break;
    default:
        break;
    }
}

void
InputManager::Update()
{
    // Update any per-frame input state here
    // This is called once per frame, after all events have been processed
}

void
InputManager::Cleanup()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

void
InputManager::InitializeJoysticks()
{
    // Initialize joystick subsystem if not already initialized
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        if (!SDL_InitSubSystem(SDL_INIT_JOYSTICK))
        {
            spdlog::error("Failed to initialize SDL Joystick subsystem: {}", SDL_GetError());
            this->joysticksInitialized = false;
            return;
        }
        spdlog::debug("SDL Joystick subsystem initialized");
    }

    int numJoysticks = 0;
    SDL_JoystickID* joystickIDs = SDL_GetJoysticks(&numJoysticks);

    if (numJoysticks > 0 && joystickIDs != nullptr)
    {
        spdlog::info("Found {} joystick(s)", numJoysticks);
        for (int i = 0; i < numJoysticks; ++i)
        {
            SDL_Joystick* joystick = SDL_OpenJoystick(joystickIDs[i]);
            if (joystick != nullptr)
            {
                joysticks.push_back(joystick);
                spdlog::info("Initialized joystick {}: {}", i, SDL_GetJoystickName(joystick));
            }
            else
            {
                spdlog::error("Failed to open joystick {}: {}", i, SDL_GetError());
            }
        }
        SDL_free(joystickIDs);
        this->joysticksInitialized = true;
    }
    else
    {
        spdlog::debug("No joysticks connected");
        this->joysticksInitialized = true; // Still mark as initialized even with no devices
    }
}

bool
InputManager::JoysticksInitialized()
{
    return this->joysticksInitialized;
}