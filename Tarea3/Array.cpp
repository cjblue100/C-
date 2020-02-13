#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Array.h"

using namespace std;

//constructor predeterminado para la clase Array (tamaño predeterminado 10)
Array::Array(int tamanioArreglo) :tamanio(tamanioArreglo > 0 ? tamanioArreglo :
	throw invalid_argument("El tamanio del arreglo debe ser mayor que 0")),
	ptr(new int[tamanio]) {
	for (size_t i = 0; i < tamanio; i++) {
		ptr[i] = 0; // establece el elemento del arreglo basado en apuntador
	}
}

//constructor de copia para la clase Array:
//debe recibir una referencia a un objeto Array
Array::Array(const Array& arregloACopiar) : tamanio(arregloACopiar.tamanio),
ptr(new int[tamanio]) {
	for (size_t i = 0; i < tamanio; i++) {
		ptr[i] = arregloACopiar.ptr[i]; //lo copia en el objeto
	}
}

Array::~Array() {
	delete[] ptr; //libera el espacio del arreglo basado en apuntador 
}

//devuelve el numero de elementos del objeto Array
size_t Array::obtenerTamanio()const {
	return tamanio; //numero de elementos en el objeto Array
}

//operador de asignacion sobrecargado
//devolucion de const evita (a1 = a2) = a3
const Array& Array::operator=(const Array& derecho) {
	if (&derecho != this) //evita la autoasignacion
	{
		//para los objetos Array de distintos tamaños, designa el arreglo
		//original del lado izquierdo, después asigna el nuevo arreglo del lado
		//izquierdo
		if (tamanio != derecho.tamanio) {
			delete[] ptr; //libera espacio
			tamanio = derecho.tamanio; //cambia el tamaño de este objeto
			ptr = new int[tamanio]; //crea espacio para la copia del arreglo
		}
		for (size_t i = 0; i < tamanio; i++) {
			ptr[i] = derecho.ptr[i]; //copia el arreglo en el objeto
		}
	}
	return *this; //permite x = y = z, por ejemplo
}

//determina si dos objetos Array son iguales y devuelve true
//en caso contrario devuelve false
bool Array::operator==(const Array& derecho) const {
	if (tamanio != derecho.tamanio)
		return false; //arreglos con distinto numero de elementos
	for (size_t i = 0; i < tamanio; i++) {
		if (ptr[i] != derecho.ptr[i])
			return false; //el contenido de los objetos Array no es igual
	}
	return true; //los objetos Array son iguales
}

//operador de subindice sobrecargado para objetos Array no const
//la devolucion de una referencia crea un lvalue modificable
int& Array::operator[](int subindice) {
	//comprueba error de subindice fuera de rango
	if (subindice < 0 || subindice >= tamanio)
		throw out_of_range("Subindice fuera de rango");

	return ptr[subindice]; //devolucion de referencia
}

//operador de subindice sobrecargado para objetos Array const
//devolucion de referencia const crea un rvalue
int Array::operator[](int subindice) const {
	//comprueba error de subindica fuera de rango
	if (subindice < 0 || subindice >= tamanio)
		throw out_of_range("Subindice fuera de rango");

	return ptr[subindice]; //devuelve una copia de este elemento
}

//operador de entrada sobrecargado para la clase Array
//recibe valores para el objeto Array completo
istream& operator>>(istream& entrada, Array& a) {
	for (size_t i = 0; i < a.tamanio; i++)
		entrada >> a.ptr[i];

	return entrada; //permite cin >> x >> y
}

//operador de salida sobrecargado para la clase Array
ostream& operator<<(ostream& salida, const Array& a) {
	//imprime arreglo private basado en ptr
	for (size_t i = 0; i < a.tamanio; i++) {
		salida << setw(12) << a.ptr[i];
		if ((i + 1) % 4 == 0) { //4 numeros por fila de salida
			salida << endl;
		}
	}

	if (a.tamanio % 4 == 0) //fin de la ultima linea de salida
		salida << endl;

	return salida; //permite cout << x << y
}