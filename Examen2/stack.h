#pragma once

#include "nodo.h"


class stack
{
private:
	nodo* primero;
	nodo* ultimo;

public:
	stack();

	void push(int, const char*);// insertar
	bool pop();// eliminar

	bool isEmpty();

	void print();
	void printRec(nodo*);
	void saveFile();


};