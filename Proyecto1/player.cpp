#include "player.h"




player::player(int _x, int _y){
	x = _x;
	y = _y;
	ma = 'm';
}

void player::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void player::drawP() 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	

	gotoxy(x, y);             //Cabeza
	SetConsoleTextAttribute(h, 14);//AUTO
	cout << (char)147 << "\n";

	gotoxy(x, y + 1);         //Cuerpo 1
	cout << (char)219;

	gotoxy(x, y + 2);         //Cuerpo 2
	cout << (char)219;

	gotoxy(x - 1, y + 1);      // Llanta superior izq
	cout << "0";

	gotoxy(x + 1, y + 1);     // LLanta superior der
	cout << "0";

	gotoxy(x - 1, y + 2);   //LLanta inferior izq
	cout << "0";

	gotoxy(x + 1, y + 2);  //Llanta inferior der
	cout << "0";
}

void player::moveP(int state, bool dead)
{
	if (_kbhit()) {
		
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		ma = _getch();

		if (ma == 'd' && x != 59 && state==0 && dead == false) {
			gotoxy(x, y);
			cout << "  ";
			gotoxy(x, y + 1);
			cout << "  ";
			gotoxy(x, y + 2);         //Cuerpo 2
			cout << " ";
			gotoxy(x - 1, y + 1);      // Llanta superior izq
			cout << "  ";
			gotoxy(x + 1, y + 1);     // LLanta superior der
			cout << "  ";
			gotoxy(x - 1, y + 2);   //LLanta inferior izq
			cout << " ";
			gotoxy(x + 1, y + 2);  //Llanta inferior der
			cout << " ";

			x += 4;
			gotoxy(x, y);
			SetConsoleTextAttribute(h, 14);
			cout << (char)147 << "\n";
			gotoxy(x, y + 1);
			cout << (char)219;
			gotoxy(x, y + 2);         //Cuerpo 2
			cout << (char)219;
			gotoxy(x - 1, y + 1);      // Llanta superior izq
			cout << "0";
			gotoxy(x + 1, y + 1);     // LLanta superior der
			cout << "0";
			gotoxy(x - 1, y + 2);   //LLanta inferior izq
			cout << "0";
			gotoxy(x + 1, y + 2);  //Llanta inferior der
			cout << "0";
		}
		else if (ma == 'a' && x != 51 && state == 0 && dead == false) {
			gotoxy(x, y);
			cout << " ";
			gotoxy(x, y + 1);
			cout << " ";
			gotoxy(x, y + 2);         //Cuerpo 2
			cout << " ";
			gotoxy(x - 1, y + 1);      // Llanta superior izq
			cout << " ";
			gotoxy(x + 1, y + 1);     // LLanta superior der
			cout << " ";
			gotoxy(x - 1, y + 2);   //LLanta inferior izq
			cout << " ";
			gotoxy(x + 1, y + 2);  //Llanta inferior der
			cout << " ";

			x -= 4;
			gotoxy(x, y);
			SetConsoleTextAttribute(h, 14);
			cout << (char)147 << "\n";
			gotoxy(x, y + 1);
			cout << (char)219;
			gotoxy(x, y + 2);         //Cuerpo 2
			cout << (char)219;
			gotoxy(x - 1, y + 1);      // Llanta superior izq
			cout << "0";
			gotoxy(x + 1, y + 1);     // LLanta superior der
			cout << "0";
			gotoxy(x - 1, y + 2);   //LLanta inferior izq
			cout << "0";
			gotoxy(x + 1, y + 2);  //Llanta inferior der
			cout << "0";

		}
	}
	// Fin Movimiento

}

char player::getMa()
{
	return ma;
}

int player::getX()
{
	return x;
}

int player::getY()
{
	return y;
}



int player::life()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(65, 33);
	SetConsoleTextAttribute(h, 10);
	cout <<"Vidas: " << vidas;

	return vidas;
}



void player::collision(int _x, int _y, int _v, int _w)
{
	if (x == _x && y == _y + 2 &&  vidas>0 || x == _v && y == _w + 2 && vidas>0)
	{
		gotoxy(x, y);
		cout << " ";
		gotoxy(x, y + 1);
		cout << " ";
		gotoxy(x, y + 2);         //Cuerpo 2
		cout << " ";
		gotoxy(x - 1, y + 1);      // Llanta superior izq
		cout << " ";
		gotoxy(x + 1, y + 1);     // LLanta superior der
		cout << " ";
		gotoxy(x - 1, y + 2);   //LLanta inferior izq
		cout << " ";
		gotoxy(x + 1, y + 2);  //Llanta inferior der
		cout << " ";
		
		

		vidas--;
	}

	


	if (vidas == 0) 
	{
		gotoxy(x + 1, y + 2);
		cout << "F";
	}
	
}

void player::Restart(bool dead, char r)
{
	if (dead == true && r == 'r')
	{

		vidas = 3;

	}
}