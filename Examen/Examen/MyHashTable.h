#pragma once
#include "HashTableVector.h"

template<class K, class V>
class MyHashTable
{
private:
	HashTableVector<K, V> _arreglo;

public:

	int Count;

	MyHashTable()
	{

	}

	void Add(K llave, V valor)
	{
		_arreglo.Add(llave, valor);
		Count++;
	}
};

