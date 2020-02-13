#include <iostream>
#include <stdexcept>
#include "Array.h"
#include <conio.h>

using namespace std;

int main() {
	Array enteros1(7); 
	Array enteros2; 


	cout << "El tamanio del objeto Array enteros1 es "
		<< enteros1.obtenerTamanio()
		<< "\nEl objeto Array despues de la inicialización es:\n" << enteros1;

	
	cout << "\nEl tamanio del objeto Array enteros2 es "
		<< enteros2.obtenerTamanio()
		<< "\nEl objeto Array despues de la inicialización es:\n" << enteros2;

	
	cout << "\nIntroduzca 17 enteros: " << endl;
	cin >> enteros1 >> enteros2;

	cout << "\nDespues de la entrada, los objetos Array contienen:\n"
		<< "enteros1:\n" << enteros1
		<< "\nenteros2:\n" << enteros2;

	//usa el operador de desigualdad (!=) sobrecargado
	cout << "\nEvaluando: enteros1 != enteros2" << endl;

	if (enteros1 != enteros2)
		cout << "enteros1 y enteros2 no son iguales" << endl;

	//crea el objeto Array enteros3, usando enteros1 como inicializador; 
	//imprime el tamaño y el contenido
	Array enteros3 = enteros1; //invoca el constructor de una copia

	cout << "\nEl tamanio del objeto Array enteros3 es "
		<< enteros3.obtenerTamanio()
		<< "\nObjeto Array despues de la inicializacion:\n" << enteros3;

	//usa el operador de asignacion (=) sobrecargado
	cout << "\nAsignando enteros2 a enteros1: " << endl;
	enteros1 = enteros2; //observe que el objeto Array de destino es más pequeño

	cout << "enteros1:\n" << enteros1
		<< "\nenteros2:\n" << enteros2;

	//usa el operador de igualdad (==) sobrecargado
	cout << "\nEvaluando: enteros1 == entero2" << endl;

	if (enteros1 == enteros2)
		cout << "enteros1 y enteros2 son iguales" << endl;

	//usa el operador de subindice sobrecargad0 para crear rvalue
	cout << "\nenteros1[5] es " << enteros1[5];

	//usa el operador de subindice sobrecargado para crear lvalue
	cout << "\n\nAsginando 1000 a enteros1[5]" << endl;
	enteros1[5] = 1000;
	cout << "enteros1:\n" << enteros1;

	//trata de usar un subindice fuera de rango
	try {
		cout << "\nTrata de asignar 1000 a enteros1[15]" << endl;
		enteros1[15] = 1000; //ERROR: subindice fuera de rango

	}
	catch (out_of_range & ex) {
		cout << "\nOcurrio una exepcion: " << ex.what() << endl;
	}

	_getch();
}