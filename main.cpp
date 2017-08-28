#include <iostream>
#include "Game.hpp"

int main(int argc, char*argv[])
{
	Game *instGame;

	instGame = new Game();

	instGame->Initialize();
	while(instGame->isRunning())
	{
		instGame->handleEvents();
		instGame->update();
	}
	instGame->Shutdown();
	return 0;
}
