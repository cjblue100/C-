#include "Inicio.h"

Inicio::Inicio(){}

void Inicio::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; 
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}




void Inicio::drawI()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// Pantalla de inicio
	gotoxy(53, 12);

	cout << "Brick crash";
	gotoxy(40, 14);
	cout << "Presione cualquier tecla para empezar";
	char ma = _getch();

	if (ma != NULL) {
		//Borrar menu de inicio
		gotoxy(53, 12);
		cout << "                   ";
		gotoxy(40, 14);
		cout << "                                                    ";
		// fin borrar menu de inicio
	}
	//Fin pantalla de inicio
}