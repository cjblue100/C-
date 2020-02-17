#pragma once
#include "Juego.h"

class Puntaje
{
public:

	Puntaje();

	void gotoxy(int x, int y);
	void insertScore(int,bool);
	void printScore(bool);
	void Restart(bool, char);

	int  puntajes[10];
	int a;
	int  y;
	int temp;
	int cosa = 0;
};