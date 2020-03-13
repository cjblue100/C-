#include "listaDoble.h"
#include <iostream>
using namespace std;

listaDoble::listaDoble() : primero(nullptr), ultimo(nullptr)
{}

bool listaDoble::estaVacia()
{
	return primero == nullptr;
}

void listaDoble::agregarElemento(int _valor)
{
	nodo* nuevo = new nodo(_valor, nullptr,nullptr);

	if (estaVacia()) 
	{
		primero = ultimo = nuevo;
	}
	else
	{
		nodo* actual = primero;
	
		while(actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
			
		}

		actual->setSiguiente(nuevo);
		nuevo->setAnterior(actual);
		ultimo = nuevo;

	}
}

void listaDoble::ordenar()
{
	nodo* actual=primero;
	
	while (actual != nullptr)
	{
		nodo* dedos = actual->getSiguiente();
		while (dedos!= nullptr)
		{
			if (actual->getValor() > dedos->getValor())
			{
				int tmp=dedos->getValor();
				dedos->setValor(actual->getValor());
				actual->setValor(tmp);
			}
			dedos = dedos->getSiguiente();
		}
		actual = actual->getSiguiente();
	}
}

void listaDoble::eliminarElemento(int _valor)
{
	if (estaVacia())
		return;


	nodo* actual = primero;

	do
	{
		if (actual->getValor() == _valor)
		{
			if (actual == primero)
			{
				primero = primero->getSiguiente();
				

				delete actual;
			}
			else if (actual == ultimo)
			{
				ultimo = ultimo->getAnterior();
				
			

				delete actual;
			}
			else
			{
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());

				delete actual;
			}
			return;
		}
		actual = actual->getSiguiente();
	} while (actual != primero);
}


void listaDoble::imprimir()
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
	}

	imprimirRec(ultimo);
}

void listaDoble::imprimirRec(nodo* _ultimate)
{
	
	if (_ultimate == nullptr) {
		return;
	}
	cout << "[ " << _ultimate->getValor() << " ]";
	imprimirRec(_ultimate->getAnterior());
	
}
