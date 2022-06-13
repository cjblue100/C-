#include"archivo.h"
#include <string>

archivo::archivo() :num(0), activeGame(false), id("")
{}



void archivo::selectQuest()
{
	if (activeGame == false)
	{
		num = (rand() % 3);
		activeGame = true;
	}

	id = to_string(num);

	ifstream guile("C://Users/Carlos/source/repos/Game/Game/Graphics/Juego1/nivel1.txt");
	guile.open("C://Users/Carlos/source/repos/Game/Game/Graphics/Juego1/nivel1.txt");
	if (guile.is_open())
	{
		while (getline(guile, pregunta)) {}
	}
}