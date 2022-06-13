#include "Juego.h"
#include "manzanaObj.h"
#include "TextureManger.h"
#include "text.h"
#include <string>
#include <iostream>

using namespace std;

text* textos,*texdos,*textres, *mensaje, *numbaLife, *textover;
manzanaObj::manzanaObj(const char* texturesheet, const char* texturesheet2, const char* manzana, const char* texturesheet3,const char* gameOver, int _x, int _y): num(0), activeGame(false), id("")
{
	
	AppleTexture = TextureManager::LoadTexture(texturesheet);
	///*wordTexture= TextureManager::LoadTexture(texturesheet2);*/
	grandeTexture = TextureManager::LoadTexture(texturesheet3);
	textos = new text(Juego::renderer, "arial.ttf", 13, " ", { 255,0,0 });
	for (int i = 0; i < 8; i++)
	{
		word[i] = ' ';
	}
	textover = new text(Juego::renderer, "arial.ttf", 25, "Esc para salir", { 250,0,0 });
	victor = 0;
	textres = new text(Juego::renderer, "arial.ttf", 13, word, { 32,32,32 });
	vidasManz1 = TextureManager::LoadTexture(manzana);
	vidasManz2 = TextureManager::LoadTexture(manzana);
	vidasManz3 = TextureManager::LoadTexture(manzana);
	over = TextureManager::LoadTexture(gameOver);
	temp = ' '; 
	x = _x;
	y = _y;
	temp = NULL;
	w = _x;
	v = _y;
	life = 3;

}

void manzanaObj::selectQuest()
{
	if (activeGame == false)
	{
		num = (rand() % 4);
		activeGame = true;
	}

	id = to_string(num);
	
	ifstream guile("C://Users/Carlos/source/repos/Game/Game/Graphics/Juego1/Nivel1.txt");
	
	if (guile.is_open())
	{
		while (getline(guile, idArchivo)) 
		{
			
			if (idArchivo == id)
			{
				getline(guile, idArchivo);
				getline(guile, pregunta);
				getline(guile, answer);
				
				break;
			}
		}
		for (int i = 0; i < pregunta.length(); i++)
		{
			respuesta[i] = pregunta.at(i);
			
		}

		textos = new text(Juego::renderer, "arial.ttf", 13, idArchivo, { 255,0,0 });
		guile.close();
		
	}

	
	
}


void manzanaObj::moveMa(SDL_Event evento, state estado)
{
	if (estado == level1) {
		y += 2;
		if (activeLetter == false)
		{
			int ascii = (rand() % 24) + 65;
			
			temp = (char)ascii;
			
			activeLetter = true;
		}
		
		if (y == 258)
		{
			
			y = 50;
			x = (rand() % 400) + 1;
			activeLetter = false;
		}
		std::string c(1, temp);
		texdos = new text(Juego::renderer, "arial.ttf", 20, c, { 255,0,0 });
		
	}
	
}

void manzanaObj::moveGra(SDL_Event evento, state estado)
{
	if (estado == level1) {
		v += 2;
		if (v == 230)
		{
			v = 50;
			w = (rand() % 400) + 1;
		}
	}
}

void manzanaObj::randomLetter()
{

	//int ascii = (rand() % 24) + 65;
	//
	//std::string c(1, ascii);
	///*cout << c << "vacio";*/
	//texdos = new text(Juego::renderer, "C://Users/Carlos/source/repos/Game/Game/arial.ttf", 20, c, { 255,0,0 });
	
}



void manzanaObj::update()
{

	
	

	srcRect.h = 200;
	srcRect.w = 200;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.w = 100;
	destRect.h = 100;

	
	srcRect2.x = 0;
	srcRect2.y = 0;

	destRect2.x = 20;
	destRect2.y = 30;
	destRect2.w = 30;
	destRect2.h = 30;

	
	
	srcRect3.h = 200;
	srcRect3.w = 200;
	srcRect3.x = 0;
	srcRect3.y = 0;

	destRect3.x = w;
	destRect3.y = v;
	destRect3.w = 100;
	destRect3.h = 100;

	apple1.x = 0;
	apple1.y = 0;
	apple1.h = 100;
	apple1.w = 100;

	destapple1.h = 75;
	destapple1.w = 75;
	destapple1.x = 345;
	destapple1.y = 0;

	apple2.x = 0;
	apple2.y = 0;
	apple2.h = 100;
	apple2.w = 100;

	destapple2.h = 75;
	destapple2.w = 75;
	destapple2.x = 370;
	destapple2.y = 0;

	apple3.x = 0;
	apple3.y = 0;
	apple3.h = 100;
	apple3.w = 100;

	destapple3.h = 75;
	destapple3.w = 75;
	destapple3.x = 395;
	destapple3.y = 0;

	srcRect4.h = 250;
	srcRect4.w = 250;
	srcRect4.x = 0;
	srcRect4.y = 0;

	destRect4.x = 80;
	destRect4.y = 50;
	destRect4.w = 300;
	destRect4.h = 150;

}
void manzanaObj::Render(state estado)
{
	if (estado == level1) {
		/*SDL_RenderCopy(Juego::renderer, AppleTexture, &srcRect, &destRect);
		SDL_RenderCopy(Juego::renderer, grandeTexture, &srcRect3, &destRect3);*/
		/*SDL_RenderCopy(Juego::renderer, palabra(), &srcRect2, &destRect2);*/
		if (life == 3 || life == 2 || life==1) {
			textos->display(20, 20, Juego::renderer);
			texdos->display(destRect.x, destRect.y, Juego::renderer);
			textres->display(20, 40, Juego::renderer);
		}else
			textover->display(12, 300, Juego::renderer);
		/*vidaLabel->display(12, 300, Juego::renderer);
		numbaLife->display(100, 300, Juego::renderer);*/
		if (life == 3) {
			SDL_RenderCopy(Juego::renderer, vidasManz1, &apple1, &destapple1);
			SDL_RenderCopy(Juego::renderer, vidasManz2, &apple2, &destapple2);
			SDL_RenderCopy(Juego::renderer, vidasManz3, &apple3, &destapple3);
		}
		else if (life == 2) {
			SDL_RenderCopy(Juego::renderer, vidasManz2, &apple2, &destapple2);
			SDL_RenderCopy(Juego::renderer, vidasManz3, &apple3, &destapple3);
		}
		else if (life == 1) {
			SDL_RenderCopy(Juego::renderer, vidasManz3, &apple3, &destapple3);
		}
		
		if (life < 1)
		{
			SDL_RenderCopy(Juego::renderer, over, &srcRect4, &destRect4);
		}
		
		if (victor == pregunta.length())
		{
			SDL_RenderCopy(Juego::renderer, over, &srcRect4, &destRect4);
		}

		

		
	}
}

SDL_Texture* manzanaObj::palabra()
{
	if (agarro == true)
	{
		return wordTexture;
	}
	return NULL;
}

SDL_Texture* manzanaObj::vidas() {
	if (life == 3 ) {
		return vidasManz1;
	}
	return NULL;
}

void manzanaObj::colision(state estado,int _x,int _y)
{
	int contador = 0;
	if (estado == level1) {

		if ((this->y >= _y + 10&& this->x <= _x + 15&& this->x >= (_x + - 2)) && this->y <= (_y+ 100)) {
			
			agarro = true;
			this->y = 22;
			this->x = (rand() % 580) + 1;

			for (int i = 0; i < 8; i++)
			{
				if (temp == respuesta[i]) {
					word[i] = temp;
					
					contador++;
					
				}
				
				
				
			}
			for (int i = 0; i < 8; i++)
			{
				if (temp != respuesta[i] && contador == 0) {
					life = life - 1;
					break;
				}
			}
			int victoria = 0;
			for (int i = 0; i < 8; i++)
			{
				if (word[i]!= ' ' ) {
					victoria++;
				}
			}
			victor = victoria;
			cout << contador;
			
			textres = new text(Juego::renderer, "arial.ttf", 13, word, { 32,32,32 });
		}

		if ((this->v >= _y && this->w <= _x && this->w >= (_x - 40)) && this->v <= (_y + 50)) {
			agarro = false;
			this->v = 22;
			this->w = (rand() % 580) + 1;
		}
	}
}

void manzanaObj::reiniciolvl(SDL_Event evento) {
	switch (evento.key.keysym.sym) {

	case SDLK_ESCAPE:
		life = 3;
		activeGame = false;
		for (int i = 0; i < 50; i++)
		{
			word[i] = ' ';
			respuesta[i] = ' ';
		}
		textres = new text(Juego::renderer, "arial.ttf", 13, word, { 32,32,32 });
		break;

	}
}