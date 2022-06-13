#include "Juego.h"
#include <Windows.h>
#include <time.h>
#include <cstdlib>
#include "text.h"
Juego* juego = nullptr;

int main(int argc, char* args[]) {

	

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	juego = new Juego();
	

	juego->init("CBR", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 460, 342, false);
	
	
	srand(time(NULL));
	while (juego->running()) 
	{
		frameStart = SDL_GetTicks();

		juego->handleEvents();
		juego->update();
		juego->render();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}
	juego->clean();

	return 0;
}