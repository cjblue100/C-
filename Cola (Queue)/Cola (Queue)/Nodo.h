#pragma once
#include <string>
using namespace std;

#ifndef NODO_H
#define NODO_H

class nodo
{
private:
	string valor;
	nodo* siguiente;
	nodo* anterior;

	friend class Queue;
public:
	nodo();
	nodo(string, nodo*, nodo*);
	

	void setValor(string);
	void setSiguiente(nodo*);
	void setAnterior(nodo*);

	string getValor();
	nodo* getSiguiente();
	nodo* getAnterior();


};




#endif
