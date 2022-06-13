#include "Inicio.h"
#include "Juego.h"
#include "TextureManger.h"
#include "GameObj.h"

Inicio::Inicio()
{
	
}

Inicio::Inicio(const char* texturesheet)
{

	objInicio = TextureManager::LoadTexture(texturesheet);

	src.x = src.y;
	src.w = dest.w = 200;
	src.h = dest.y= 200;

	dest.x = dest.h=0;
}

void Inicio::drawInicio() 
{
	TextureManager::Draw(objInicio, src, dest);
}


void Inicio::update(){}

void Inicio::estadoRender(bool estado, const char* texturesheet, const char* texturesheet2)
{
	if (estado == false) 
	{
		objInicio = TextureManager::LoadTexture(texturesheet);
		Juego::setState(mapa);
	}
	else if(estado==true)
	{
		Juego::setState(start);
		objInicio = TextureManager::LoadTexture(texturesheet2);
		
	}
}

void Inicio::enterLVL(int level, const char* texturesheet2, const char* texturesheet,state estado,SDL_Event evento)
{
	
	if (estado == mapa && level ==2)
	{
		if (evento.type == SDL_KEYDOWN)
		{
			switch (evento.key.keysym.sym) {

			case SDLK_RETURN:
				objInicio = TextureManager::LoadTexture(texturesheet);
				Juego::setState(level1);
			break;

			

			}
		}
	}
	else if (estado == level1)
	{
		switch (evento.key.keysym.sym) {

		case SDLK_ESCAPE:
			objInicio = TextureManager::LoadTexture(texturesheet2);
			Juego::setState(mapa);
			break;

		}
	}
	
}



void Inicio::Render()
{
	SDL_RenderCopy(Juego::renderer, objInicio, NULL, NULL);
}
