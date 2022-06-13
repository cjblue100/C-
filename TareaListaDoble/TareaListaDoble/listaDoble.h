#pragma once
#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodo.h"

class listaDoble
{
private:
	nodo* primero;
	nodo* ultimo;

public:
	listaDoble();

	void agregarElemento(int);
	
	
	
	bool estaVacia();
	void Unite(listaDoble);
	void imprimir();
	void imprimirRec(nodo*);
};



#endif // !LISTADOBLE_H

