#pragma once
#include "Juego.h"

class mapa
{
public:

	mapa();
	mapa(const char* texturesheet);
	~mapa();

	void loadmapa();
	void drawmapa();

	void update();
	void Render();

private:
	int x;
	int y;

	SDL_Rect src, dest;
	SDL_Texture* objInicio;



};