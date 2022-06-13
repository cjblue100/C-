#include "Imagenes.h"
#include <SDL.h>
#include <iostream>
#include "movimiento.h"
using namespace std;



void Imagenes::setDimensions() 
{
	hola.x = 200;
	hola.y = 120;
	hola.h = 100;
	hola.w = 100;

	map.h = 1000;
	map.w = 2000;

	select.x = 172;
	select.y = 141;
}

void Imagenes::setX(SDL_Rect _ima, int _pos) 
{
	_ima.x = _pos;
}

void Imagenes::setY(int _pos)
{
	hola.y = _pos;
}


void Imagenes::loadbmp(SDL_Window* wind)
{
	
	

	imagenmundo = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/menu.bmp");
	flecha = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/flecha.bmp");
	mapa = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/mapajuego1.bmp");
	mapa2 = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/mapajuego2.bmp");
	
	

}


void Imagenes::printbmp(SDL_Window* wind)
{
	holamundowindow = SDL_GetWindowSurface(wind);
	SDL_BlitSurface(imagenmundo, NULL, holamundowindow, NULL);
	SDL_BlitSurface(flecha, NULL, holamundowindow, &hola);
	
	SDL_UpdateWindowSurface(wind);
}

void ventana::destroywind(SDL_Window* wind)
{
	SDL_DestroyWindow(wind);
	SDL_Quit();
}


void movimiento::moveCursor(SDL_Window* wind, SDL_Event evento)
{

	while (SDL_PollEvent(&evento))
	{
		if (evento.type == SDL_KEYDOWN)
		{

			switch (evento.key.keysym.sym) {
			case SDLK_UP:
				hola.y = 120;
				flecha = NULL;
				SDL_FreeSurface(flecha);

				SDL_UpdateWindowSurface(wind);
				flecha = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/flecha.bmp");
				SDL_BlitSurface(flecha, NULL, holamundowindow, &hola);


				break;
			case SDLK_DOWN:
				hola.y = 300;
				flecha = NULL;
				SDL_FreeSurface(flecha);
				SDL_UpdateWindowSurface(wind);
				flecha = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/flecha.bmp");
				SDL_BlitSurface(flecha, NULL, holamundowindow, NULL);
				break;


			}
		}
		/*else if (SDL_QUIT == eventohola.type) {
			return 1;
		}*/


	}
}

	
	
	




