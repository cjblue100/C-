#pragma once
#include "Juego.h"

class GameObj
{
	public:

		GameObj(const char* texturesheet,int x,int y);
		~GameObj();

		void update();
		void Render();
		void moveCursor(SDL_Event evento);
		void borraFlecha();
		bool pressEnter(SDL_Event evento,int,state);
		void estadoRender(bool, const char* texturesheet);
		int evaluateY();

private:
	int x;
	int y;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	

};