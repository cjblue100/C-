#pragma once
#include "Juego.h"

class playerObj
{
public:
	playerObj();
	playerObj(const char* texturesheet,const char* texturesheet2, const char* texturesheet3, int x, int y);
	~playerObj();

	void moveP(SDL_Event evento, state estado);
	void colision(state estado);
	int getX();
	int getY();
	void update();
	void Render(state estado);
	void timer();
	
private:
	int x;
	int y;
	float speed=4.0, horizon,vertical;
	int cst;
	SDL_Texture* playerTexture;
	SDL_Texture* playerTexture2;
	SDL_Texture* playerTexture3;
	SDL_Rect srcRect, destRect;
};
