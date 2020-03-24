#include "stack.h"

stack::stack() : primero(nullptr), ultimo(nullptr)
{
}

bool stack::isEmpty()
{
	return primero == nullptr;
}

void stack::push(int _valor, const char* _nombre)
{
	nodo* nuevo = new nodo(_valor, _nombre, nullptr, nullptr);

	if (isEmpty())
	{
		primero = ultimo = nuevo;
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
		ultimo = nuevo;

	}

	
}

bool stack:: pop()
{
	if (isEmpty())
	{
		return false;
	}

	nodo* actual = ultimo;

	if (actual == ultimo)
	{
		ultimo = ultimo->getAnterior();

		delete actual;
	}
	return true;
}

void stack::print()
{
	printRec(primero);
}