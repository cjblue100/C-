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

	
}



void listaDoble::Unite(listaDoble lista)
{
	if (estaVacia())
		cout << "Lista vacia";
	else
	{
		nodo* actual = primero;

		while (actual != nullptr)
		{
			
			lista.agregarElemento(actual->getValor());
			actual = actual->getSiguiente();
		}
		
	}


	
}