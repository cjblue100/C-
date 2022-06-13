#pragma once
#ifndef VENTANA_H
#define VENTANA_H
#include <SDL.h>

const int WIDTH = 1152, HEIGHT = 648;



class ventana
{
public:

	/*SDL_Window* window = SDL_CreateWindow("CBR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);*/

	
	//Inicio Renderizar imagenes
	/*SDL_Surface collecion de pixeles e informacion extra como el formato
	SDL_texture lo mismo que _Surface pero guarda de manera mas eficiente*/
	SDL_Surface* flecha = NULL;
	SDL_Surface* holamundowindow = NULL;
	SDL_Surface* imagenmundo = NULL;
	SDL_Surface* mapa = NULL;
	SDL_Surface* pla = NULL;
	SDL_Surface* mapa2 = NULL;

	/*SDL_Renderer* window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* arrow = SDL_CreateTextureFromSurface(window_renderer, flecha);
	SDL_Texture* ventanaa = SDL_CreateTextureFromSurface(window_renderer, holamundowindow);
	SDL_Texture* menu = SDL_CreateTextureFromSurface(window_renderer, imagenmundo);
	SDL_Texture* maps = SDL_CreateTextureFromSurface(window_renderer, mapa);
	SDL_Texture* player = SDL_CreateTextureFromSurface(window_renderer, pla);
	SDL_Texture* map2 = SDL_CreateTextureFromSurface(window_renderer, mapa2);*/
	//FIN Renderizar imagenes

	SDL_Rect hola;
	SDL_Rect map;
	SDL_Rect select;
	

	/*void setDimensions();
	void loadbmp();
	void printbmp();
	void setX(SDL_Rect, int);
	void setY(int);*/
	
	void destroywind(SDL_Window*);

	/*void moveCursor();
	void moveSelectL();
	void movePlayer();*/
};


#endif
