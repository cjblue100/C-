#pragma once
#include "nodo.h"
using namespace std;
#include <fstream>



struct usuarioRegistro
{
	int valor;
	const char* nombre;
};



class stack
{
private:
	nodo* primero;
	nodo* ultimo;
	fstream usuario;
public:
	stack();

	void push(int, const char*);// insertar
	bool pop();// eliminar

	bool isEmpty();

	void print();
	void printRec(nodo*);
	void saveFile();


};
