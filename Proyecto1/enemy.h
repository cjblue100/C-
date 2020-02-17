#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <cstdlib>
#include "Juego.h"
#include "player.h"

class enemy
{
public:
	enemy(int _y,int _w);
	~enemy();

	void gotoxy(int x,int y);
	void drawE();
	void drawE2();
	void moveE(int, bool, int,int);

	void secondE(int, bool, int, int );
	void brandon();
	int getX();
	int getY();
	int getW();
	int getV();

	int getScore();
	void printScore();
	void Restart(bool, char);
	int score;

private:
	int pos,  x, y,v,w;
	

};



#endif // !1
