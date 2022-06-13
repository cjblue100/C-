#include "nodo.h"

nodo::nodo() : valor(-1), siguiente(nullptr)
{}

nodo::nodo(int _valor, nodo* _siguiente,nodo* _anterior)
{
	setValor(_valor);
	setSiguiente(_siguiente);
	setAnterior(_anterior);
}

void nodo::setValor(int _valor)
{
	this->valor = _valor;
}

void nodo::setSiguiente(nodo* _siguiente)
{
	this->siguiente = _siguiente;
}

void nodo::setAnterior(nodo* _siguiente)
{
	this->anterior = _siguiente;
}

int nodo::getValor()
{
	return this->valor;
}


nodo* nodo::getSiguiente()
{
	return this->siguiente;
} 

nodo* nodo::getAnterior()
{
	return this->anterior;
}