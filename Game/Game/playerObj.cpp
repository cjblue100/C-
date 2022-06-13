#include "Juego.h"
#include "playerObj.h"
#include "TextureManger.h"
#include<conio.h>
#include<windows.h>
#include <thread>
#include <chrono>
#include <mutex>

playerObj::playerObj() : x(1), y(1),horizon(0),vertical(0)
{}

playerObj::playerObj(const char* texturesheet, const char* texturesheet2, const char* texturesheet3, int _x, int _y)
{
	
	playerTexture = TextureManager::LoadTexture(texturesheet);
	
	x = _x;
	y = _y;
}

void playerObj::moveP(SDL_Event evento,state estado)
{
	if (estado == level1) {
		if (evento.type == SDL_KEYDOWN)
		{

			switch (evento.key.keysym.sym) {
			case SDLK_RIGHT:
				if (x < 400)
					horizon = 1;
				else
					horizon = 0;
				break;
			case SDLK_LEFT:
				if (x > 5)
					horizon = -1;
				else
					horizon = 0;
				break;
			}
		}
		if (evento.type == SDL_KEYUP) 
		{
			switch (evento.key.keysym.sym) {
			case SDLK_RIGHT:
				
					/*x+=10;*/
					horizon = 0;
				break;
			case SDLK_LEFT:
				
					/*x-=10;*/
					horizon = 0;
				break;
			}
		}
		
			x += horizon * speed;
		

	}
}

int playerObj::getX()
{
	return x;
}

int playerObj::getY()
{
	return y;
}


void playerObj::update()
{
	srcRect.h = 200;
	srcRect.w = 200;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.w = 100;
	destRect.h = 100;
}

void playerObj::Render(state estado)
{
	
	if (estado == level1) {
		SDL_RenderCopy(Juego::renderer, playerTexture, &srcRect, &destRect);
	}
	
	
}
