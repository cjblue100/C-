#pragma once
#include "Juego.h"


class Inicio
{
public:

	Inicio();
	Inicio(const char* texturesheet);
	~Inicio();

	void loadInicio();
	void drawInicio();
	void estadoRender(bool, const char* texturesheet, const char* texturesheet2);
	void enterLVL(int level, const char* texturesheet2, const char* texturesheet, state estado, SDL_Event evento);
	
	void update();
	void Render();

private:
	int x;
	int y;
	
	SDL_Rect src, dest;
	SDL_Texture* objInicio;
	SDL_Texture* objMapa;
	
};

