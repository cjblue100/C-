#pragma once

#ifndef NODO_H
#define NODO_H

class nodo
{
private:
	int valor;
	char* arreglo;
	nodo* siguiente;
	nodo* anterior;

public:
	nodo();
	nodo(int,const char*, nodo*,nodo*);
	

	void setInfo(int);

	
	void setSiguiente(nodo*);
	void setAnterior(nodo*);
	

	void saveToFile();

	int getValor();
	char* getNombre();
	nodo* getSiguiente();
	nodo* getAnterior();


};




#endif


