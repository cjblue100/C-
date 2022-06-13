#pragma once
#include "Juego.h"

class dificulty
{
public:
	dificulty();


	void gotoxy(int x, int y);
	int timer(int, bool);
	int getDif(int,char);
	void Restart(bool dead, char r);
	void printLVL();
	int getScore();

	int lvl, dificultad, score;

	 int s=0;

};
