#include "listaEnlazadaSimple.h"
#include <iostream>
#include <iostream>
using namespace std;

listaEnlazada::listaEnlazada() : primero(nullptr), Top(nullptr)
{}

bool listaEnlazada::estaVacia()
{
	return primero == nullptr;
}

void listaEnlazada::push(int _valor)
{
	nodo* nuevo = new nodo(_valor, nullptr,nullptr);

	if (estaVacia())
	{
		primero = nuevo;
	}
	else
	{
		nodo* actual = primero;

		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}

		actual->setSiguiente(nuevo);
		nuevo->setAnterior(actual);
		Top = nuevo;
	}
}

void listaEnlazada::pop(int _valor)
{
	if (estaVacia())
		cout << "Lista vacia";
	else
	{

		/*nodo* actual = primero;
		nodo* anterior = nullptr;*/
		
		nodo* anterior = Top->getAnterior();
		nodo* fin = Top;
		Top = anterior;
		anterior->setSiguiente(nullptr);

		delete fin;
		
		
		
		
		/*while (actual != nullptr)
		{

			if (actual->getValor() == _valor)
			{
				if (actual == primero)
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

		}*/
	}
}

int listaEnlazada::size()
{
	if (estaVacia())
		return 0;
	else
	{
		nodo* actual = primero;
		int tamanio = 0;
		while (actual != nullptr)
		{
			tamanio++;
			actual = actual->getSiguiente();
		}
		
		return tamanio;
	}
}

int listaEnlazada::top()
{
	return Top->getValor();
}

void listaEnlazada::imprimir()
{
	if (estaVacia())
		cout << "Lista vacia";
	else
	{
		nodo* actual = primero;

		while (actual != nullptr)
		{

			cout << "[ " << actual->getValor() << " ]";
			actual = actual->getSiguiente();
		}
		cout << "\n";
		cout << "Tamanio: " << size() << "\n";
		cout << "Top: " << top();
	}

}