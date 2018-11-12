#include "../include/Game.hpp"

void Game::Init()
{
	static InputType configModules;
	this->Inputmanager = new InputHandler();
	this->WindowManager = new WindowModule();
	configModules = Window;
	this->Inputmanager->attachObserver(Window, this->WindowManager);
	this->running = true;
}

void Game::Shutdown()
{
	delete this->Inputmanager;
	delete this->WindowManager;
	this->Inputmanager->attachObserver(Window, this->WindowManager);
	this->running = false;
}

Game::Game() //Handles Configurations
{
}
Game::~Game() //No idea..calls shutdown
{
	this->Shutdown();
}
