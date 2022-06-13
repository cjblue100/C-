#pragma once
#include "MiLista.h"
#include "HashTableNodoPair.h"

template<class K, class V>
class HashTableVectorNodo
{
private:
	MiLista<HashTableNodoPair<K, V>> _elementos;

public:
	
	void Add(K llave, V valor)
	{
		Nodo<HashTableNodoPair<K, V>>* cursor = _elementos.FirstOrDefault();
		
		while (cursor != nullptr)
		{
			HashTableNodoPair<K, V> pareja = cursor->GetValor();
			if (pareja.Key == llave)
				throw "An item with the same key has already been added";

			cursor = cursor->GetSiguiente();
		}

		HashTableNodoPair<K, V> nuevoValor(llave, valor);
		_elementos.AddFirst(nuevoValor);
	}

};

