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
	void ordenar();
	void eliminarElemento(int);
	
	bool estaVacia();

	void imprimir();
	void imprimirRec(nodo*);
};



#endif // !LISTADOBLE_H

