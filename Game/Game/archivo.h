#pragma once
#include "Juego.h"
#include <fstream>
using namespace std;


class archivo
{
public:
	archivo();
	int brandom();
	void selectQuest();

private:
	
	bool activeGame;
	int num;
	std::string id, pregunta, respuesta;
};
