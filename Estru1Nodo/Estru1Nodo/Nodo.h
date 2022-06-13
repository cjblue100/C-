#pragma once
template <class T>
class Nodo
{
private:
	T dato;
	Nodo* siguiente;
public:
	Nodo* GetSiguiente()
	{
		return siguiente;
	}

	void SetSiguiente(Nodo* siguiente) {
		this->siguiente = siguiente;
	}

	T GetValor() {
		return dato;
	}

	void SetValor(T valor) {
		this->dato = valor;
	}

	Nodo(T valor) : dato(valor), siguiente(nullptr)
	{

	}
};

