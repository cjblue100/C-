#pragma once
#ifndef JUEGO_H
#define JUEGO_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <SDL_ttf.h>


enum state{start,mapa,level1};

class Juego 
{
public:
	Juego();
	~Juego();

	void handleEvents();
	void init(const char* tittle,int x, int y, int w,int h, bool fullscreen);
	void update();
	void render();
	void clean();
	bool running();
	void close(SDL_Event evento,int pos);
	
	static state getState();
	static state setState(state);


	static SDL_Renderer* renderer;
	SDL_Window* window;
private:
	int cnt = 0;
	bool isRunning;
	
	

	
};


#endif
