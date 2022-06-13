#pragma once
#include <vector>
#include "HashTableVectorNodo.h"
#include <stdio.h>      
#include <stdlib.h>

using namespace std;

template<class K, class V>
class HashTableVector
{
private:
	vector<HashTableVectorNodo<K, V>> _arreglo;

	int HashFunction(K llave)
	{
		int indice = 54654 % 1000;
		return indice;
	}

public:
	HashTableVector()
	{
		_arreglo.resize(1000);
	}

	void Add(K llave, V valor)
	{
		int indice = HashFunction(llave);
		_arreglo[indice].Add(llave, valor);
	}


};

