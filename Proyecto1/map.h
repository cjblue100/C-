#pragma once
#ifndef MAP_H
#define MAP_H
#include "Juego.h"

class map
{
public:
	map();
	~map();

	void gotoxy(int x, int y);
	void drawMap();
	void colition();

private:
	int x, y;
	HANDLE h;

};


#endif // !MAP_H

