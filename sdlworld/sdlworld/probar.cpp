#include <iostream>

#include "stdio.h"
#include <SDL.h>

using namespace std;

#define WIDTH 640
#define HEIGHT 480


int main(int argc, char* argv[])
{
	SDL_Window* window{}; // apuntador para la ventana que haremos
	SDL_Surface* surface; // buffer de graficos
	
	//flags que pasan por la funciono de inicializacion
	int flags = SDL_INIT_VIDEO;// 
	int status = SDL_Init(flags); //pasamos las flags por la funcion y recibimos un int diciendo que paso

	if (status == 0) //0 significa que todo esta bien
	{
		const char* titulo = "Hello Nurse";
		int x = SDL_WINDOWPOS_UNDEFINED;
		int y = SDL_WINDOWPOS_UNDEFINED;
		int width = WIDTH;
		int height = HEIGHT;
		window = SDL_CreateWindow(titulo,x,y,width,height,SDL_WINDOW_SHOWN);

		if (window) 
		{
			surface = SDL_GetWindowSurface(window);
			
			SDL_Rect* rect = NULL; // el null significa que pintara toda la pantalla
			//El formato es rojo, verde y azul.
			Uint32 color = SDL_MapRGB(surface->format, 0, 255, 0);
			SDL_FillRect(surface,rect,color); // esta funcion dibuja un rectangulo
			
			SDL_UpdateWindowSurface(window); 

			SDL_Delay(2000); // milisegundos
		}
		else
		{
			printf("Error");

		}
	}
	else 
	{
		printf("Error");
	}


	SDL_DestroyWindow(window); // limpia la ventana
	SDL_Quit(); // termina los procesos de SDL

	

	return 0;
}

