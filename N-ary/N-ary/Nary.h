#pragma once
#include "Nodo.h"
class Nary {
private:

public:
	Nodo* Raiz;

	Nary(int valor) {
		Raiz = new Nodo(valor);
	}
	
	void agregar(int valor, int papa) {
		add(valor, papa, Raiz);
	}

	void add(int valor,int padre, Nodo*raiz) {
		Nodo* nuevo = new Nodo(valor);
		
		if (padre == raiz->valor) 
			raiz->_hijos.push_back(nuevo);
		else 
		{
			for (int x = 0;x < raiz->_hijos.size();x++)
			{
				if (raiz->_hijos[x]->valor == padre) {
					raiz->_hijos[x]->_hijos.push_back(nuevo);
					break;
				}
				else
				{
					add(valor,padre,raiz->_hijos[x]);
				}
			}
		}
		
	}

	
};
