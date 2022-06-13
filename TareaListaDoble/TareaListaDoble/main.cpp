#include "listaDoble.h"
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	listaDoble lista;
	listaDoble lista2;
	lista.agregarElemento(4);
	lista.agregarElemento(2);
	lista.agregarElemento(1);
	lista.agregarElemento(3);

	lista2.agregarElemento(6);
	lista2.agregarElemento(7);
	lista2.agregarElemento(8);
	lista2.agregarElemento(9);
	
	cout << "Lista1: "<<endl;
	lista.imprimir();

	cout << endl<<"Lista2: "<<endl;
	lista2.imprimir();
	
	lista2.Unite(lista);
	
	cout << endl << "Union: " << endl;
	lista.imprimir();

	_getch();
}