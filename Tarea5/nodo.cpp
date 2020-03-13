#include "nodo.h"

nodo::nodo() : valor(-1), siguiente(nullptr), anterior((nullptr))
{}

nodo::nodo(int _valor, nodo* _anterior, nodo* _siguiente)
{
	setValor(_valor);
	setAnterior(_anterior);
	setSiguiente(_siguiente);
}

void nodo::setValor(int _valor)
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