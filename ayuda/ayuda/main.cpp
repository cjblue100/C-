#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <SDL_ttf.h>
#include <time.h>
#include <Windows.h>
const int WIDTH = 700, HEIGHT = 399;

using namespace std;
int agarro = 0;

int main(int argc, char* agrv[]) {

	SDL_Surface* back = NULL;
	SDL_Surface* window = NULL;
	SDL_Surface* stick = NULL;
	SDL_Surface* apple = NULL;
	SDL_Surface* granada = NULL;
	SDL_Rect tamanio;
	SDL_Rect coordManz;
	SDL_Rect coordGrenade;
	tamanio.x = 250;
	tamanio.y = 250;
	tamanio.h = 100;
	tamanio.w = 100;


	int l1 = tamanio.x; //left
	int r1 = tamanio.x + tamanio.w; //right
	int t1 = tamanio.y; //top
	int b1 = tamanio.y + tamanio.h; //bottom



	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL No se incializo, error: " << SDL_GetError() << endl;
	}

	TTF_Init();

	SDL_Window* ventana = SDL_CreateWindow(" PROTOTIPO NIVEL 1 ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

	SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, 0);
	TTF_Font* font = TTF_OpenFont("arial.ttf", 25);
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* superficie = TTF_RenderText_Solid(font, "Gravedad", color);
	SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);

	SDL_Renderer* renderer2 = SDL_CreateRenderer(ventana, -1, 0);
	TTF_Font* font2 = TTF_OpenFont("arial.ttf", 25);
	SDL_Color color2 = { 255, 255, 255 };
	SDL_Surface* superficie2 = TTF_RenderText_Solid(font2, "d", color2);
	SDL_Texture* textura2 = SDL_CreateTextureFromSurface(renderer2, superficie2);

	int texW2 = 0;
	int texH2 = 0;

	//SDL_QueryTexture(textura,NULL, NULL, &texW2, &texH2);
	SDL_Rect dstrect2 = { 100,100,texW2,texH2 };

	window = SDL_GetWindowSurface(ventana);
	back = SDL_LoadBMP("Background.bmp");
	stick = SDL_LoadBMP("Stick2.bmp");
	apple = SDL_LoadBMP("apple.bmp");
	granada = SDL_LoadBMP("granada.bmp");


	if (ventana == NULL) {
		cout << "No se pudo crear la ventana" << SDL_GetError() << endl;

		return EXIT_FAILURE;
	}
	srand(time(NULL));

	SDL_Event evento;

	coordManz.x = 250;
	coordManz.y = 22;
	coordManz.h = 100;
	coordManz.w = 100;
	coordGrenade.x = 100;
	coordGrenade.y = 22;

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(textura, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { 0,0,texW,texH };

	while (true) {
		if (SDL_PollEvent(&evento)) {
			if (SDL_QUIT == evento.type) {
				break;
			}
		}
		switch (evento.type) {
		case SDL_KEYDOWN: // A keypress
			switch (evento.key.keysym.sym) {
			case SDLK_LEFT:
				tamanio.x -= 1;

				break;
			case SDLK_RIGHT:
				tamanio.x += 1;
				break;
			}

		}

		coordManz.y += 1;
		int posx = tamanio.x;
		int posy = tamanio.y;

		SDL_BlitSurface(back, NULL, window, NULL);
		SDL_BlitSurface(stick, NULL, window, &tamanio);
		SDL_BlitSurface(apple, NULL, window, &coordManz);
		SDL_BlitSurface(granada, NULL, window, &coordGrenade);
		SDL_BlitSurface(superficie, NULL, window, &dstrect);


		if ((coordManz.y >= tamanio.y && coordManz.x >= posx && coordManz.x <= (posx + 50)) && coordManz.y <= (posy + 100)) {
			coordManz.y = 22;
			coordManz.x = (rand() % 580) + 1;
		}

		if ((coordGrenade.y >= tamanio.y && coordGrenade.x >= posx && coordGrenade.x <= (posx + 50)) && coordGrenade.y <= (posy + 100)) {

			coordGrenade.y = 22;
			coordGrenade.x = (rand() % 580) + 1;

		}
		coordGrenade.y += 1;
		if (coordGrenade.y == 355) {

			coordGrenade.y = 22;
			coordGrenade.x = (rand() % 580) + 1;
		}

		if (coordManz.y == 355) {

			coordManz.y = 22;
			coordManz.x = (rand() % 580) + 1;

		}
		SDL_BlitSurface(superficie2, NULL, window, &dstrect2);
		SDL_UpdateWindowSurface(ventana);
		Sleep(2);


	}
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(ventana);
	TTF_Quit();
	SDL_Quit();

	return EXIT_SUCCESS;
}