#include "Juego.h"
#include "GameObj.h"
#include "TextureManger.h"


GameObj::GameObj(const char* texturesheet, int _x, int _y)
{
	
	objTexture = TextureManager::LoadTexture(texturesheet);

	x = _x;
	y = _y;
}

void GameObj::moveCursor(SDL_Event evento)
{
	if (evento.type == SDL_KEYDOWN)
	{

		switch (evento.key.keysym.sym) {
		case SDLK_LEFT:
			
			x = 60;

			break;
		case SDLK_RIGHT:
			x = 200;
		}
	}
}


bool GameObj::pressEnter(SDL_Event evento,int pos, state estado)
{
	if (evento.type == SDL_KEYDOWN)
	{
		if (estado == start) 
		{
			switch (evento.key.keysym.sym) {
			case SDLK_RETURN:

				if (pos == 0)

					return false;

				break;

			}
		}

		if (estado == mapa)
		{
			switch (evento.key.keysym.sym) {
			case SDLK_ESCAPE:

					return true;

				break;

			}
		}
	}
}

int GameObj::evaluateY()
{
	if (x == 60)
		return 0;
	else if (x == 200)
		return 1;
}



void GameObj::estadoRender(bool estado, const char* texturesheet)
{
	if (estado == false)
		objTexture = NULL;
	else if (estado == true)
	{
		objTexture = TextureManager::LoadTexture(texturesheet);
	}
}


void GameObj::update()
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

void GameObj::Render()
{
	SDL_RenderCopy(Juego::renderer, objTexture, &srcRect, &destRect);
}