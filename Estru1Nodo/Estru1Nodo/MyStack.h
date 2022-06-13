#pragma once
#include "MiLista.h"

template<class T>
class MyStack
{
private:

	MiLista<T> _lista;

public:
	int Count;

	MyStack() {}

	void Push(T data) {
		_lista.AddFirst(data);
		Count++;
	}

	T Pop()
	{
		if (Count > 0) {
			Nodo<T>* primero = _lista.FirstOrDefault();
			_lista.RemoveFirst();
			Count--;
			return primero->GetValor();
		}

		throw "Stack is empty";
	}

	T Peek(T item)
	{
		if (Count > 0) {
			Nodo<T>* primero = _lista.FirstOrDefault();
			return primero->GetValor();
		}

		throw "Stack is empty";
	}
};

