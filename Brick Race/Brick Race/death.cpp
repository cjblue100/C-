#include "death.h"

death::death(){}

bool death::PGame(int life)
{
	if (life == 0)
		return true;

	return false;
}


void death::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void death::drawDeath(bool dead)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// Pantalla de pause
	gotoxy(10, 12);
	if (dead == true) {
		cout << "GameOver";
		gotoxy(10, 14);
		cout << "Presione la tecla\"R\" para Reiniciar";
			 

	}

	if (dead == false) {
		//Borrar menu de inicio
		gotoxy(10, 12);
		cout << "          ";
		gotoxy(10, 14);
		cout << "                                    ";
		// fin borrar menu de inicio
	}
}


