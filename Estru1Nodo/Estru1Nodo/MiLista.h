#pragma once
#include "Nodo.h"
template<class T>

class MiLista
{
private:
private:
	Nodo<T>* primero, * ultimo;
public:
	int Count;

	MiLista() {
		primero = nullptr;
		ultimo = nullptr;
		Count = 0;
	}

	Nodo<T>* FirstOrDefault() {
		return primero;
	}

	void AddFirst(T data) {
		Nodo<T>* nuevo = new Nodo<T>(data);
		Nodo<T>* temp = primero;

		primero = nuevo;
		primero->SetSiguiente(temp);

		if (Count == 0) {
			ultimo = primero;
		}

		Count++;
	}

	//Complejidad de tiempo: O(1)
	void Add(T data) {
		if (primero == nullptr) {
			primero = new Nodo<T>(data);
			ultimo = primero;
			Count++;
		}
		else {
			Nodo<T>* nuevo = new Nodo<T>(data);
			ultimo->SetSiguiente(nuevo);
			ultimo = ultimo->GetSiguiente();
			Count++;
		}
	}

	void RemoveLast()
	{
		if (Count == 1) {
			primero = nullptr;
			ultimo = nullptr;
			Count--;
		}
		else
		{
			Nodo<T>* actual = primero;
			while (actual->GetSiguiente() != ultimo)
			{
				actual = actual->GetSiguiente();
			}

			actual->SetSiguiente(nullptr);
			ultimo = actual;
			Count--;
		}
	}


	void RemoveFirst()
	{
		if (Count != 0) {
			//2 -> 5
			primero = primero->GetSiguiente();
			Count--;

			if (Count == 0)
			{
				ultimo->SetSiguiente(nullptr);
			}
		}
	}

	void Remove(T item)
	{
		Nodo<T>* anterior = nullptr;
		Nodo<T>* actual = primero;

		while (actual != nullptr)
		{
			if (actual->GetValor() == item)
			{
				if (anterior != nullptr) {

					anterior->SetSiguiente(actual->GetSiguiente());
					if (actual->GetSiguiente() == nullptr)
						ultimo = anterior;

					Count--;
					break;
				}
				else {
					RemoveFirst();
					break;
				}
			}

			anterior = actual;
			actual = actual->GetSiguiente();
		}
	}

};

