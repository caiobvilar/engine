#include "../include/Game.hpp"

int main(int argc, char *argv[])
{
	Game *game = new Game();
	game->Init();

	while(game->isRunning()) // Main Loop
	{
		//Handles Events
		game->HandleEvents();
		//Update States
		game->Update();
		//Render changes
		game->Render();
	}
	delete game; //Calls game Clean() method
	game = NULL;
	return 0;
}
