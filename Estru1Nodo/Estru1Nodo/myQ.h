#pragma once
#include "MiLista.h"

template<class T>

class myQ
{
private:
	MiLista<T> _lista;
public:
	int count;
	
	void Enqueue(T data)
	{
		_lista.Add(data);
		count++;
	}

	T Dequeue()
	{
		if (count > 0)
		{
			auto temp=_lista.FirstOrDefault();
			_lista.RemoveFirst();
			count--;
			return temp->GetValor();
		}

		throw "Queue is empty";
	}

	T Peek(T item)
	{
		if (count > 0) {
			Nodo<T>* primero = _lista.FirstOrDefault();
			return primero->GetValor();
		}

		throw "Stack is empty";
	}


};
