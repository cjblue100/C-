#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);

public:
	explicit Array(int = 10); //constructor predeterminado
	Array(const Array&); //constructor de copia
	~Array(); //destructor
	size_t obtenerTamanio() const; //devuelve el tamaño 

	const Array& operator=(const Array&); // operador de asignacion
	bool operator==(const Array&) const; //operador de igualdad

	//operador de desigualdad: devuelve el opuesto del operador ==
	bool operator!=(const Array& derecho) const {
		return !(*this == derecho); //invoca a Array::operador==
	}

	//el operador de subindice para los objetos no const devuelve un lvalue modificable 
	int& operator[](int);

	//el operador de subindice para los objetos no const devuelve rvalue
	int operator[](int) const;

private:
	size_t tamanio; //arreglo tamanio basado en apuntador
	int* ptr; //apuntador al primer elemento del arreglo basado en apuntador;
};
#endif 

