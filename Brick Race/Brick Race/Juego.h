#pragma once
#ifndef JUEGO_H
#define JUEGO_H
#include<windows.h>
#include <iostream>
#include "conio.h"
using namespace std;

enum {inicio, game};

class Juego
{
public:
	Juego();
	~Juego();

	
	void consolCursor(bool);
	void handleEvents();
	void init();
	
	
	bool running();
	
	
private :
	bool isRunning;
	
	

	
};



#endif // !JUEGO_H


