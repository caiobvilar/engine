#define	FPS	60
#define	DELAY_TIME	1000.0f/FPS

int main(int argc, char *argv[])
{
	uint32_t frameStart,frameTime;
	while(game->isRunning()) // Main Loop
	{
		frameStart = SDL_GetTicks();
		//Handles Events
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME)
		{
			SDL_Delay((int) (DELAY_TIME - frameTime));
		}
	}
	return 0;
}
