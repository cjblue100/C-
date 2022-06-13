#include <iostream>
using namespace std;
#include <SDL.h>
#include <Windows.h>
#include <processenv.h>
#include <conio.h>
#include "movimiento.h"
#include "imagenes.h"
//const int WIDTH = 1152, HEIGHT = 648;
#include "Juego.h"

Juego* juego = nullptr;


int main(int argc, const char* argv[]) {

	juego = new Juego();

	while (juego->running()) {

		juego->handleEvents();
		juego->update();
		juego->render();
	}
	juego->clean();

	return 0;
}