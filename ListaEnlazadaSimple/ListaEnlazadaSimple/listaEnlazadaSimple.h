#pragma once

#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "nodo.h"

class listaEnlazada
{
private:
	nodo* primero;

public:
	listaEnlazada();

	void agregarElemento(int);
	void eliminarElemento(int);

	bool estaVacia();

	void imprimir();

};







#endif
