#ifndef __GAME__HPP
#define __GAME__HPP
	
class Game
{
	public:
		Game(); //constructor
		~Game();//destructor,both will do nothing
		void Initialize();

		void update();
		void handleEvents();//mostly window and user input events
		void Shutdown();
		bool isRunning();
	private:
		bool running = false;
		SDL_Window *main_Win;
		SDL_Renderer* main_Render;
}



#endif /*__GAME__HPP */
