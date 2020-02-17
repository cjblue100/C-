#include "Juego.h"

Juego* juego = nullptr;

int main()
{
	juego =new Juego();

	juego->init();
	juego->consolCursor(false);
	
	while (juego->running())
	{
		juego->handleEvents();

	}
	
}