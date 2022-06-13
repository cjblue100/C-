#pragma once
#include "SDL_ttf.h"
#include "Juego.h"
#include <string>

using namespace std;

class TextureManager 
{

public:
	static SDL_Texture* LoadTexture(const char* fileName );
	static SDL_Texture*  FontSurface(const char* texto);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	
	

	

	
};
