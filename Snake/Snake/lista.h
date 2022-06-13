#pragma once
#include "Nodo.h"



class lista 
{
private:
	Nodo* primero;
	Nodo* ultimo;
	
public:
	lista() 
	{
		primero = new Nodo();
	}

	bool isEmpty()
	{

	}

	void agregarNodo()
	{
		Nodo* nuevo = new Nodo();

		Nodo* actual = primero;

		while (actual->siguiente != nullptr)
		{
			actual = actual->siguiente;
		}

		actual->siguiente = nuevo;
		nuevo->anterior = actual;
		
		ultimo = nuevo;

	}

	int tamanio()
	{
		int size = 0;

		Nodo* actual = primero;

		while (actual != nullptr)
		{

			size++;
			actual = actual->siguiente;
		}
		return size;
	}
};