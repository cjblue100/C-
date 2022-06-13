#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Juego.h"

class player
{
public:
	player(int _x, int _y);
	~player();

	void drawP();
	void moveP(int,bool);
	void gotoxy(int x, int y);
	int getX();
	int getY();
	int life();
	void setLife(int);
	void collision(int x, int y,int , int);
	char getMa();
	void Restart(bool, char);
	bool cerrar(char);

	char ma;
private:
	int x, y, vidas=3;

};

#endif

