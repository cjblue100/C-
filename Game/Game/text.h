#pragma once
#include "Juego.h"
#include <string>

class text
{
public:
	text(SDL_Renderer* render,const std::string& font, int font_size, const std::string& message_text, const SDL_Color& color);
	void display(int x, int y,SDL_Renderer* renderer)const;
	
	static SDL_Texture* loadFont(SDL_Renderer* render,const std::string& font, int font_size, const std::string& message_text, const SDL_Color& color);

private:

	SDL_Texture* _text_texture = nullptr;
	mutable SDL_Rect rect;

};
