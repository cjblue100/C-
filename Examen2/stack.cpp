#include "stack.h"
#include <iostream>
#include <fstream>
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
		primero = primero->getSiguiente();
		
		
		
	}
	return true;
}

void stack::print()
{
	printRec(primero);
	
}

void stack::printRec(nodo* _primero)
{
	if (_primero == nullptr)
		return;

	cout << "[ " << _primero->getValor() << " / " << _primero->getNombre() << " ]";
	printRec(_primero->getSiguiente());


}

void stack::saveFile()
{
	
	usuario.open("usuario.dat", ios::in | ios::out | ios::app | ios::binary);

	usuarioRegistro save;

	nodo* actual = primero;

	while (actual->getSiguiente() != nullptr)
	{
		save.valor = actual->getValor();
		save.nombre = actual->getNombre();
		
		usuario.write(reinterpret_cast<const char*>(&save), sizeof(usuarioRegistro));
		
		actual = actual->getSiguiente();

	}

	usuario.close();

	cout << "\nArchivo creado";

}
