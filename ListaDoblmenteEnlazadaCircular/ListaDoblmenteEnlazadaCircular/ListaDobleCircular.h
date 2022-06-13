#pragma once

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodo.h"


class ListaDobleCircular
{
private:
	nodo* primero;
	nodo* ultimo;

public:
	ListaDobleCircular();

	bool estaVacia();
	void agregarElemento(int);//Agrega al final de la lista
	void insertarElemento(int, int);//Inserta en una posicion indicada en la lista

	int obtenerTamano();

	void eliminarElemento(int);

	void imprimir();
	void imprimirReversa();






};








#endif