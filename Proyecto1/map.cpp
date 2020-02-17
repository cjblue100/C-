
#include "map.h"

map::map()
{
	
}

void map::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}



void map::drawMap() 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//Bloques
	for (int b = 39;b > 10;b--) {
		gotoxy(49, b);
		SetConsoleTextAttribute(h, 1);
		cout << (char)219 << "\n";

		gotoxy(61, b);
		
		cout << (char)219 << "\n";
	}

}