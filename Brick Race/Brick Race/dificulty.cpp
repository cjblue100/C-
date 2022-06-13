#include "dificulty.h"

dificulty::dificulty() 
{
	lvl = 1;
	dificultad = 100;
	score = 20;

}


void dificulty::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int dificulty::timer(int state, bool dead)
{
	
	if (state == 0 && dead==false) {
		s++;
		//aqui vamos a usar el sleep para ver el tiempo , para no verlo tan rapido ni lento sino normal como un conometro
		if (s > 194)
			s = 0;

		
	}
	
	if (s == 194)
		return s;
}

int dificulty::getDif(int segundos, char forward)
{
	if (segundos== 194 && lvl<10 ) 
	{
		lvl++;
		dificultad -= 10;
	}

	if (lvl == 10)
	{
		dificultad = 1;
	}

	int guarda = dificultad;
	int faster=NULL;
	if (forward == 'w')
	{
		
		if(dificultad == 100)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 90)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 80)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 70)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 60)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 50)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 40)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 30)
		{
			faster = 10;
			return faster;
		}
		if (dificultad == 20)
		{
			faster = 10;
			return faster;
		}

		if (dificultad == 10)
		{
			faster = 0;
			return faster;
		}
	}
	dificultad = guarda;
	return dificultad;
}

void dificulty::printLVL()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	gotoxy(63, 30);
	SetConsoleTextAttribute(h, 12);
	cout << (char)201;

	gotoxy(77, 30);
	SetConsoleTextAttribute(h, 12);
	cout << (char)187;


	for (int x = 64;x < 77;x++) {
		gotoxy(x, 30);
		SetConsoleTextAttribute(h, 12);
		cout << (char)205;
	}


	for (int v = 33;v > 30;v--) 
	{
		gotoxy(63, v);
		cout << (char)186;
	}

	for (int v = 33;v > 30;v--)
	{
		gotoxy(77, v);
		cout << (char)186;
	}

	for (int x = 64;x < 77;x++) {
		gotoxy(x, 34);
		SetConsoleTextAttribute(h, 12);
		cout << (char)205;
	}

	gotoxy(77, 34);
	cout << (char)188;

	gotoxy(63, 34);
	cout << (char)200;


	gotoxy(65, 31);
	SetConsoleTextAttribute(h, 10);
	cout << "Nivel: " << lvl;
	
	
}

int dificulty::getScore()
{
	if (lvl == 1)
		score=20;
	if (lvl == 2)
		score = 40;
	if (lvl == 3)
		score = 60;
	if (lvl == 4)
		score = 80;
	if (lvl == 5)
		score = 100;
	if (lvl == 6)
		score = 130;
	if (lvl == 7)
		score = 170;
	if (lvl == 8)
		score = 200;
	if (lvl == 9)
		score = 220;
	if (lvl == 10)
		score = 280;

	return score;

}



void dificulty::Restart(bool dead, char r)
{
	if (dead == true && r == 'r')
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		gotoxy(65, 31);
		SetConsoleTextAttribute(h, 14);
		cout << "Nivel: " << "      ";

		s = 0;
		lvl = 1;
		dificultad = 100;
		

	}
}

