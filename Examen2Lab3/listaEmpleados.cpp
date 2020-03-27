#include "listaEmpleados.h"
#include <iostream>
#include <fstream>
lista::lista() : primero(nullptr), ultimo(nullptr)
{
}

bool lista::ifEmpty()
{
	return primero == nullptr;
}

void lista::agregarlista(int _id, string _name, float _salario)
{
	empleado* nuevo = new empleado(_id,_name,_salario,true,nullptr,nullptr);
	
	
	if (ifEmpty())
	{
		primero =ultimo= nuevo;
		return;
	}
	else
	{
		empleado* actual = primero;

		while (actual->getSiguente() != nullptr)
		{
			actual = actual->getSiguente();
		}
		actual->setSiguiente(nuevo);
		nuevo->setAnterior(actual);
		ultimo = nuevo;
	}
}

void lista::imprimirLista()
{
	if (ifEmpty())
	{
		cout << "Aqui no hay nada";
		return;
	}
	else
	{
		empleado* actual = primero;

		do 
		{
			actual->imprimir();
			cout << "\n ";
			actual = actual->getSiguente();

		} while (actual != nullptr);
	}
}

void lista::eliminar(int id)
{
	if (ifEmpty())
	{
		cout << "Aqui no hay nada para borrar";
		return;
	}
	else
	{
		
		empleado* actual = primero;
		while (actual != nullptr) {
			if (actual->getID() == id)
			{
				if (actual == primero)
				{
					primero = primero->getSiguente();

					delete actual;
				}
				else if (actual == ultimo)
				{
					ultimo = ultimo->getAnterior();

					delete actual;
				}
				else
				{
					actual->getAnterior()->setSiguiente(actual->getSiguente());
					actual->getSiguente()->setAnterior(actual->getAnterior());

					delete actual;
				}
				return;
			}
			
			actual = actual->getSiguente();
		}
	}

}


void lista::desactivarEmpleado(int id)
{
	if (ifEmpty())
	{
		cout << "No hay nada que desactivar";
	}
	else
	{
		empleado* actual = primero;
		while (actual != nullptr)
		{
			if (actual->getID() == id)
			{
				actual->setActivo(false);
				return;
			}
			actual = actual->getSiguente();
		}
	}
}

void lista::guardarEmpleado()
{
	if (ifEmpty())
	{
		cout << "No hay  nada que pasar a un archivo";
	}
	else
	{
		empleado* actual = primero;
		fstream file("Esclavos.dat", ios::in | ios::out | ios::app | ios::binary);
		registroEmpleados archie;
		while (actual != nullptr)
		{
			if (actual->getActivo() == true)
			{
				archie.code = actual->getID();
				archie.nomb = actual->getName();
				archie.moni = actual->getSalario();

				file.seekp(0, ios::end);
				file.write(reinterpret_cast<const char*>(&archie), sizeof(registroEmpleados));
			}
			actual = actual->getSiguente();
		}
		cout << "\nArchivo creado con exito";
		file.close();
	}

}
