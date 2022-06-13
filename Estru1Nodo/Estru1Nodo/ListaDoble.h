#pragma once
#include "NodoDoble.h"

template<class T>
class MiListaDoble
{
private:
	NodoDoble<T>* primero, * ultimo;
public:
	int Count;

	MiListaDoble() {
		primero = nullptr;
		ultimo = nullptr;
		Count = 0;
	}

	NodoDoble<T>* FirstOrDefault() {
		return primero;
	}

	//Complejidad de tiempo: O(1)
	void Add(T data) {
		if (primero == nullptr)
		{
			primero = new NodoDoble<T>(data);
			ultimo = primero;
			Count++;
		}
		else {
			NodoDoble<T>* nuevo = new NodoDoble<T>(data);
			ultimo->SetSiguiente(nuevo);
			nuevo->SetAnterior(ultimo);
			ultimo = ultimo->GetSiguiente();
			Count++;
		}
	}

};


