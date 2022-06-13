#pragma once
#ifndef MOVIEMIENTO_H
#define MOVIEMIENTO_H
#include <SDL.h>

#include"Imagenes.h"


class movimiento:public ventana
{
public:
	movimiento();

	void moveCursor(SDL_Window* , SDL_Event);
	void moveSelectL();
	void movePlayer();
};



#endif
