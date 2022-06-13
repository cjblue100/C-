#include "movimiento.h"
#include "Imagenes.h"
#include "ventana.h"
#include <SDL.h>

Imagenes l;
movimiento::movimiento() 
{}

//void movimiento::moveCursor(SDL_Window* wind, SDL_Event evento)
//{
//	
//	flecha = NULL;
//	SDL_FreeSurface(flecha);
//
//	SDL_UpdateWindowSurface(wind);
//	flecha = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/flecha.bmp");
//	SDL_BlitSurface(flecha, NULL, holamundowindow, &hola);
//	
//	
//		/*if (evento.type == SDL_KEYDOWN)
//		{
//
//			switch (evento.key.keysym.sym) {
//			case SDLK_UP:
//				l.setY(120);
//				flecha = NULL;
//				SDL_FreeSurface(flecha);
//
//				SDL_UpdateWindowSurface(wind);
//				flecha = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/flecha.bmp");
//				SDL_BlitSurface(flecha, NULL, holamundowindow, &hola);
//
//				break;
//			case SDLK_DOWN:
//				
//				flecha = NULL;
//				l.setY(300);
//				SDL_FreeSurface(flecha);
//				SDL_UpdateWindowSurface(wind);
//				flecha = SDL_LoadBMP("C://Users/Carlos/source/repos/Geme/Geme/Graphics/Imagenes/flecha.bmp");
//				SDL_BlitSurface(flecha, NULL, holamundowindow, NULL);
//				break;
//			}
//
//
//		}*/
//		
//
//
//	
//	
//}
