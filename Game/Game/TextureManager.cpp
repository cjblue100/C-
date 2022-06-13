#include "TextureManger.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) 
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Juego::renderer,tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;

}

SDL_Texture* TextureManager::FontSurface(const char* texto)
{
	TTF_Font* fontot = TTF_OpenFont("arial.ttf", 20);
	SDL_Color color{ 255,0,0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(fontot, texto, color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(Juego::renderer, textSurface);
	

	cout << "entro";

	

	return text;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Juego::renderer, tex, &src, &dest);
}