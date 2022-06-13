#pragma once
template <class T>
class NodoDoble
{
private:
	T dato;
	NodoDoble* siguiente;
	NodoDoble* anterior;
public:
	NodoDoble* GetSiguiente()
	{
		return siguiente;
	}

	void SetSiguiente(NodoDoble* siguiente) {
		this->siguiente = siguiente;
	}

	NodoDoble* GetAnterior()
	{
		return anterior;
	}

	void SetAnterior(NodoDoble* anterior) {
		this->anterior = anterior;
	}

	T GetValor() {
		return dato;
	}

	void SetValor(T valor) {
		this->dato = valor;
	}

	NodoDoble(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr)
	{

	}
};

