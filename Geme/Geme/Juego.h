#pragma once
#ifndef JUEGO_H
#define JUEGO_H
#include "SDL.h"
#include <stdio.h>

class Juego
{
public:
	Juego();
	~Juego();

	void handleEvents();
	void init(const char* tittle, int x, int y, int w, int h, bool fullscreen);
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;


};


#endif

