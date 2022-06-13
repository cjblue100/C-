#include "nodo.h"

nodo::nodo() : valor(-1), siguiente(nullptr)
{}

nodo::nodo(int _valor, nodo* _siguiente)
{
	setValor(_valor);
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