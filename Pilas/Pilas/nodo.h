#pragma once

#ifndef NODO_H
#define NODO_H

class nodo
{
private:
	int valor;
	nodo* siguiente;

public:
	nodo();
	nodo(int, nodo*,nodo*);
	nodo* anterior;

	void setValor(int);
	void setSiguiente(nodo*);
	void setAnterior(nodo*);

	int getValor();
	nodo* getSiguiente();
	nodo* getAnterior();


};




#endif
