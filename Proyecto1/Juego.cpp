#include "Juego.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "Inicio.h"
#include "Pause.h"
#include "death.h"
#include "dificulty.h"
#include "Puntaje.h"
Inicio* menu;
player* play;
enemy* enee;
map* mapa;
Pause* stop;
death* mortality;
dificulty* dificultad;
Puntaje* eva;

Juego::Juego()
{}



void Juego::consolCursor(bool showFlag) 
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Juego::init()
{
	menu = new Inicio();
	play = new player(55, 37);
	enee = new enemy( 10,10);
	stop = new Pause(0);
	mortality = new death();
	dificultad = new dificulty();
	eva = new Puntaje();
	isRunning = true;
	menu->drawI();
	mapa->drawMap();
	play->drawP();
	enee->drawE();
	enee->drawE2();
	
	
}




void Juego::handleEvents()
{
	
	play->moveP(stop->PGame(play->getMa()),mortality->PGame(play->life()));
	dificultad->printLVL();
	enee->printScore();
	enee->moveE(stop->PGame(play->getMa()), mortality->PGame(play->life()), 
			    dificultad->getDif(dificultad->timer(stop->PGame(play->getMa()), 
			    mortality->PGame(play->life())), play->getMa()),dificultad->getScore());

	enee->secondE(stop->PGame(play->getMa()), mortality->PGame(play->life()),
			dificultad->getDif(dificultad->timer(stop->PGame(play->getMa()),
			mortality->PGame(play->life())), play->getMa()), dificultad->getScore());


	play->collision(enee->getX(),enee->getY(),enee->getV(),enee->getW());
	play->life();
	stop->drawPause();
	mortality->drawDeath(mortality->PGame(play->life()));
	dificultad->Restart(mortality->PGame(play->life()), play->getMa());
	eva->insertScore(enee->getScore(), mortality->PGame(play->life()));
	eva->Restart(mortality->PGame(play->life()), play->getMa());
	enee->Restart(mortality->PGame(play->life()), play->getMa());
	play->Restart(mortality->PGame(play->life()), play->getMa());
	
	eva->printScore(mortality->PGame(play->life()));
	

	
}


bool Juego::running()
{
	return isRunning;
}

