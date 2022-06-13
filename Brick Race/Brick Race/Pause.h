#pragma once
#include "Juego.h"
#ifndef PAUSE_H
#define PAUSE_H

class Pause
{
public:

	Pause(int);
	~Pause();

	int PGame(char);
	void gotoxy(int x, int y);
	void drawPause();
	int state = 0;

	
};




#endif // !PAUSE_H


