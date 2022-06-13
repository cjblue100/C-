#include "enemy.h"

enemy::enemy(int _y, int _w) {
	x = 51;
	v = 59;
	y = _y;
	w = _w;
	score = 0;
}

void enemy::brandon()
{
	if (x < 55)
		x = 51;
	if (x > 55)
		x = 59;

	if (v < 55)
		v = 51;
	if (v > 55)
		v = 59;

	if (x == v && x > 55)
		v = 51;

	if (x == v && x < 55)
		v = 59;

	if (x == v && x == 55)
		v = 51;
}

void enemy::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void enemy::drawE() 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//Sprite Enemigo
	gotoxy(x, y); //Cabeza
	SetConsoleTextAttribute(h, 3);//AUTO
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

	gotoxy(x + 1, y+ 2);  //Llanta inferior der
	cout << "0";
	////Fin sprite
}

void enemy::drawE2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//Sprite Enemigo
	gotoxy(v, w); //Cabeza
	SetConsoleTextAttribute(h, 3);//AUTO
	cout << (char)147 << "\n";

	gotoxy(v, w + 1);         //Cuerpo 1
	cout << (char)219;

	gotoxy(v, w + 2);         //Cuerpo 2
	cout << (char)219;

	gotoxy(v - 1, w + 1);      // Llanta superior izq
	cout << "0";

	gotoxy(v + 1, w + 1);     // LLanta superior der
	cout << "0";

	gotoxy(v - 1, w + 2);   //LLanta inferior izq
	cout << "0";

	gotoxy(v + 1, w + 2);  //Llanta inferior der
	cout << "0";
	////Fin sprite
}
void enemy::moveE(int state, bool killed,int dificulty,int puntuacion)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (y < 37 && state == 0 && killed==false) {
		//Sprite Enemigo
		/*int w = 51;*/
		gotoxy(x, y); //Cabeza
		SetConsoleTextAttribute(h, 3);//AUTO
		cout << " ";
	
		gotoxy(x, y + 1);         //Cuerpo 1
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

		y++;

		gotoxy(x, y); //Cabeza
		SetConsoleTextAttribute(h, 15);//AUTO
		cout << (char)147 << "\n";
		

		gotoxy(x, y + 1);         //Cuerpo 1
		cout << (char)219;

		gotoxy(x, y + 2);         //Cuerpo 2
		cout << (char)219;

		gotoxy(x - 1, y + 1);      // Llanta superior izq
		cout << "0";

		//gotoxy(x + 1, y + 1);     // LLanta superior der
		//cout << "0";

		gotoxy(x - 1, y + 2);   //LLanta inferior izq
		cout << "0";

		gotoxy(x + 1, y + 2);  //Llanta inferior der
		cout << "0";
		Sleep(dificulty);
		//Fin sprite
	}

	if (y == 37) 
	{
		score += puntuacion;
		
		gotoxy(x, y); //Cabeza
		SetConsoleTextAttribute(h, 3);//AUTO
		cout << " ";

		gotoxy(x, y + 1);         //Cuerpo 1
		cout << " ";

		gotoxy(x, y + 2);         //Cuerpo 2
		cout << " ";

		gotoxy(x - 1, y + 1);      // Llanta superior izq
		cout << " ";

		//gotoxy(x + 1, y + 1);     // LLanta superior der
		//cout << " ";

		gotoxy(x - 1, y + 2);   //LLanta inferior izq
		cout << " ";

		gotoxy(x + 1, y + 2);  //Llanta inferior der
		cout << " ";
		x = rand() % 8 + 51;

		enemy::brandon();
		y = 10;
	}

}


void enemy::secondE(int state, bool killed, int dificulty, int puntuacion)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (w < 37 && state == 0 && killed == false) {
		//Sprite Enemigo
		/*int w = 51;*/
		gotoxy(v, w); //Cabeza
		SetConsoleTextAttribute(h, 3);//AUTO
		cout << " ";

		gotoxy(v, w + 1);         //Cuerpo 1
		cout << " ";

		gotoxy(v, w + 2);         //Cuerpo 2
		cout << " ";

		gotoxy(v - 1, w + 1);      // Llanta superior izq
		cout << " ";

		gotoxy(v + 1, w + 1);     // LLanta superior der
		cout << " ";

		gotoxy(v - 1, w + 2);   //LLanta inferior izq
		cout << " ";

		gotoxy(x + 1, w + 2);  //Llanta inferior der
		cout << " ";

		w++;

		gotoxy(v, w); //Cabeza
		SetConsoleTextAttribute(h, 15);//AUTO
		cout << (char)147 << "\n";


		gotoxy(v, w + 1);         //Cuerpo 1
		cout << (char)219;

		gotoxy(v, w + 2);         //Cuerpo 2
		cout << (char)219;

		gotoxy(v - 1, w + 1);      // Llanta superior izq
		cout << "0";

		gotoxy(v + 1, w + 1);     // LLanta superior der
		cout << "0";

		gotoxy(v - 1, w + 2);   //LLanta inferior izq
		cout << "0";

		gotoxy(v + 1, w + 2);  //Llanta inferior der
		cout << "0";
		Sleep(dificulty);
		//Fin sprite
	}

	if (w == 37)
	{
		score += puntuacion;

		gotoxy(v, w); //Cabeza
		SetConsoleTextAttribute(h, 3);//AUTO
		cout << " ";

		gotoxy(v, w + 1);         //Cuerpo 1
		cout << " ";

		gotoxy(v, w + 2);         //Cuerpo 2
		cout << " ";

		gotoxy(v - 1, w + 1);      // Llanta superior izq
		cout << " ";

		gotoxy(v + 1, w + 1);     // LLanta superior der
		cout << " ";

		gotoxy(v - 1, w + 2);   //LLanta inferior izq
		cout << " ";

		gotoxy(v + 1, w + 2);  //Llanta inferior der
		cout << " ";
		v = rand() % 8 + 51;

		enemy::brandon();
		w = 10;
	}

}



int enemy::getX()
{
	return x;
}

int enemy::getY()
{
	return y;
}


int enemy::getV() 
{
	return v;
}

int enemy::getW()
{
	return w;
}

void enemy::printScore()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(65, 32);
	SetConsoleTextAttribute(h, 10);
	cout << "Score: " << score;
}

int enemy::getScore()
{
	return score;
}

void enemy::Restart(bool dead, char r)
{
	if (dead == true && r == 'r')
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		gotoxy(65, 32);
		SetConsoleTextAttribute(h, 14);
		cout << "Score: " << "      ";

		score = 0;

	}
}