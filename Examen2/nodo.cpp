#include "nodo.h"
#include "iostream"

using namespace std;
nodo::nodo() : valor(-1), siguiente(nullptr),anterior(nullptr)
{
	arreglo = nullptr;
}

nodo::nodo(int _valor, const char*  _arreglo, nodo* _siguiente, nodo* _anterior)
{
	arreglo = new char[30];
	strcpy_s(arreglo, strlen(_arreglo) + 1, _arreglo);
	setInfo(_valor);
	setAnterior(_anterior);
	setSiguiente(_siguiente);
}

void nodo::setInfo(int _valor)
{
	this->valor = _valor;
	
	

}

void nodo::setSiguiente(nodo* _siguiente)
{
	this->siguiente = _siguiente;
}

int nodo::getValor()
{
	return this->valor;
}

char* nodo::getNombre()
{
	return this->arreglo;
}

nodo* nodo::getSiguiente()
{
	return this->siguiente;
}

void nodo::setAnterior(nodo* _anterior)
{
	this->anterior = _anterior;
}

nodo* nodo::getAnterior()
{
	return this->anterior;
}