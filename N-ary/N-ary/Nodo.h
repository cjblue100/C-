#pragma once
#include <iostream>
using namespace std;
#include <vector>
class Nodo {
private:

public:
	Nodo(int numero):valor(numero) {

	}
	Nodo* padre;
	int valor;
	vector<Nodo*> _hijos;

};
