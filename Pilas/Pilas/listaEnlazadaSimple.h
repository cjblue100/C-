#pragma once

#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "nodo.h"

class listaEnlazada
{
private:
	nodo* primero;
	nodo* Top;

public:
	listaEnlazada();

	void push(int);
	void pop(int);
	int size();
	int top();
	bool estaVacia();

	void imprimir();

};







#endif
