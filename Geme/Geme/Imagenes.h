#pragma once
#ifndef IMAGENES_H
#define IMAGENES_H
#include <SDL.h>
#include "ventana.h"




class Imagenes: public ventana
{

public:


	void moveCursor(SDL_Window*, SDL_Event);

	void setDimensions();
	void loadbmp(SDL_Window*);
	void printbmp(SDL_Window*);
	void setX(SDL_Rect, int);
	void setY(int);
	void bo();
};

#endif // !IMAGENES_H

