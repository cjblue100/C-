#include "Pause.h"

Pause::Pause(int sta) 
{
	state = sta;
}

int Pause::PGame(char p) 
{
	
	if (_kbhit()) 
	{
		
		if (p == 'p') 
			state = 1;
		if (p == 'c')
			state = 0;
	}

	return state;

}

void Pause::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Pause::drawPause()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// Pantalla de pause
	gotoxy(69, 12);
	if (state == 1) {
		cout << "Pause";
		gotoxy(69, 14);
		cout << "Presione la tecla\"c\" dos veces para continuar";
		
	}

	if (state == 0) {
		//Borrar menu de inicio
		gotoxy(69, 12);
		cout << "          ";
		gotoxy(69, 14);
		cout << "                                                       ";
		// fin borrar menu de inicio
	}
	//Fin pantalla de inicio
}

