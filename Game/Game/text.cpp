#include "text.h"
using namespace std;


text::text(SDL_Renderer* render,const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color& color)

{
	
	_text_texture = loadFont(render,font_path,font_size,message_text,color);
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &rect.w, &rect.h);


}



void text::display(int x, int y, SDL_Renderer* renderer)const
{
	rect.x = x;
	rect.y = y;

	SDL_RenderCopy(renderer, _text_texture, nullptr, &rect);
}

SDL_Texture* text::loadFont(SDL_Renderer* render,const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color& color)
{
	TTF_Font* font = TTF_OpenFont("arial.ttf", font_size);
	TTF_Init();
	
	if (!font)
	{
		cout << "No fuente";
		
	}

	SDL_Surface* text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);

	if (!text_surface)
		cout << "No text_Surface";

	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(render, text_surface);

	if (!text_texture)
		cout << "No text_texture";

	SDL_FreeSurface(text_surface);

	return text_texture;
}
