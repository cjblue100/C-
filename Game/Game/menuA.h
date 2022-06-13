#pragma once
#include "Juego.h"

class menuA
{
public:
	menuA(const char* texturesheet, const char*, int x, int y);
	~menuA();
	void update();
	void Render(state estado);
	int getLVL();
	void selectLVL(SDL_Event,state estado);

private:
	int x;
	int y;
	int lvl;

	SDL_Texture* objSelector;
	SDL_Texture* imgManz;
	SDL_Rect srcRect, destRect;
	SDL_Rect manzana, pera;
	SDL_Rect srcDetalle, destDetalle;

};
