#include <iostream>
#include <conio.h>

using namespace std;

int potencia(int, int);

int main()
{
	int* valorPtr;
	valorPtr = nullptr;

	int valor;
	valor = 5;

	valorPtr = &valor;

	cout << "La direccion de memoria de valorptr: " << valorPtr;
	cout << "\nValor depositado en la direccion de memoria: " << *valorPtr;

	valor = 15;
	cout << "\nLa direccion de memoria de valorptr: " << valorPtr;
	cout << "\nValor depositado en la direccion de memoria: " << *valorPtr <<"\n";

	int b = 3;
	int e = 3;

	int* bptr = &b;
	int* eptr = &e;
	int r = potencia(b, e);

	_getch();
}


int potencia(int base, int exponente)
{
	int* bptr = &base;
	int* eptr = &exponente; 
	int resultado = base * base * base;
	return resultado;
}
