#include "Juego.h"
#include "menuA.h"
#include "TextureManger.h"
#include "text.h"

text* descripcion;
text* descripcion2;

menuA::menuA(const char* texturesheet, const char* _manzana,  int _x, int _y)
{
	objSelector = TextureManager::LoadTexture(texturesheet);
	imgManz = TextureManager::LoadTexture(_manzana);
	

	descripcion = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
		"En desarrollo...", { 0,0,128 });
	descripcion2= new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
		"Regresa mas tarde", {0,0,128 });
	x = _x;
	y = _y;
	lvl = 1;
}

void menuA::selectLVL(SDL_Event evento,state estado)
{
	if (evento.type == SDL_KEYDOWN && estado==mapa)
	{

		switch (evento.key.keysym.sym) {
		case SDLK_RIGHT:
			if (lvl < 3) {
				
				if (lvl == 1) {
					x = 205;
					y = 80;
					descripcion = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"Newton va en su busqueda por ", { 0,0,128 });
					descripcion2 = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"las definiciones de la fisica", { 0,0,128 });
					


				}

				if (lvl == 2) 
				{
					x = 365;
					y = 80;
					descripcion = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"En desarrollo...", { 0,0,128 });
					descripcion2 = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"Regresa mas tarde", { 0,0,128 });
				}
				lvl++;
			}
			break;
		case SDLK_LEFT:

			if (lvl > 1) {
				
				if (lvl == 3) {
					x = 205;
					y = 80;

					descripcion = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"Newton va en su busqueda por ", { 0,0,128 });
					descripcion2 = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"las definiciones de la fisica", { 0,0,128 });

				}

				if (lvl == 2) {
					x = 28;
					y = 80;

					descripcion = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"En desarrollo...", { 0,0,128 });
					descripcion2 = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20,
						"Regresa mas tarde", { 0,0,128 });
				}

				lvl--;
			}
			break;
		}
	}
}

int menuA::getLVL()
{
	return lvl;
}



void menuA::update()
{
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.w = 64;
	destRect.h = 64;

	manzana.x = 0;
	manzana.y = 0;
	manzana.h = 100;
	manzana.w = 100;

	pera.h = 75;
	pera.w = 75;
	pera.x = 42;
	pera.y = 0;

	
	
}

void menuA::Render(state estado)
{
	if (estado == mapa) {
		descripcion->display(90, 28, Juego::renderer);
		descripcion2->display(90, 45, Juego::renderer);
		SDL_RenderCopy(Juego::renderer,imgManz, &manzana,&pera);
		SDL_RenderCopy(Juego::renderer, objSelector, &srcRect, &destRect);
		
	}
}