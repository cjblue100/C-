#include "listaEnlazadaSimple.h"
#include <iostream>
#include <iostream>
using namespace std;

listaEnlazada::listaEnlazada() : primero(nullptr)
{}

bool listaEnlazada::estaVacia()
{
	return primero == nullptr;
}

void listaEnlazada::agregarElemento(int _valor)
{
	nodo* nuevo = new nodo(_valor, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
	}
	else
	{
		nodo* actual = primero;

		while (actual->getSiguiente()!=nullptr)
		{
			actual = actual->getSiguiente();
		}

		actual->setSiguiente(nuevo);
	}
}

void listaEnlazada::eliminarElemento(int _valor)
{
	if (estaVacia())
		cout << "Lista vacia";
	else
	{
		nodo* actual = primero;
		nodo* anterior = nullptr;
		while (actual!=nullptr)
		{
			
			if (actual->getValor() == _valor)
			{
				if(actual == primero)
				{
					nodo* copiaP = primero;
					primero = primero->getSiguiente();
					delete copiaP;
				}
				else
				{
					anterior->setSiguiente(actual->getSiguiente());
					delete actual;
				}

				return;

			}

			anterior = actual;
			actual = actual->getSiguiente();

		}
	}
}


void listaEnlazada::imprimir()
{
	if (estaVacia())
		cout << "Lista vacia";
	else
	{
		nodo* actual = primero;

		while (actual!=nullptr)
		{

			cout << "[ " << actual->getValor() << " ]";
			actual = actual->getSiguiente();
		}
		cout << "\n";
	}

}