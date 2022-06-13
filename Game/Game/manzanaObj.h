#pragma once
#include "Juego.h"
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
class manzanaObj
{
public:
	manzanaObj(const char* texturesheet, const char* texturesheet2, const char*,const char* texturesheet3, const char* gameOver,
		 int x, int y);
	~manzanaObj();

	void moveMa(SDL_Event evento, state estado);
	void moveGra(SDL_Event evento, state estado);
	void printQuest(const std::string pregunta);
	void randomLetter();
	void colision(state, int, int);
	
	int brandom();
	void selectQuest();


	SDL_Texture* palabra();
	SDL_Texture* vidas();
	SDL_Color changeColor();
	void reiniciolvl(SDL_Event);
	void update();
	void Render(state estado);

private:
	char respuesta[50];
	int x,v;
	int y,w;
	char temp;
	char word[50];
	int life;
	int victor;
	bool activeGame;
	int num;
	std::string id,idArchivo, pregunta, answer;

	std::string s;
	bool activeLetter = false;
	bool agarro = false;
	SDL_Texture* vidasManz1;
	SDL_Texture* vidasManz2;
	SDL_Texture* vidasManz3;
	SDL_Texture* AppleTexture;
	SDL_Texture* grandeTexture;
	SDL_Texture* wordTexture;
	SDL_Texture* over;
	SDL_Texture* vida;
	SDL_Rect srcRect, destRect;
	SDL_Rect srcRect2, destRect2;
	SDL_Rect srcRect3, destRect3;
	SDL_Rect srcRect4, destRect4;
	SDL_Rect apple1, destapple1;
	SDL_Rect apple2, destapple2;
	SDL_Rect apple3, destapple3;

};
