#pragma once
#include <ostream>
#include <iostream>
#ifndef POLINOMIO_H
#define POlINOMIO_H

class polinomio
{

	friend std::ostream& operator<<(std::ostream&, const polinomio&);
	friend polinomio& operator +(const polinomio&, const polinomio&);
	friend polinomio& operator -(const polinomio&, const polinomio&);
	friend polinomio& operator *(const polinomio&, const polinomio&);

private:
	int coeficientes[30];
	int exponentes[30];
	int cantidad;

public:
	polinomio();
	~polinomio();
	void ingresarTerminos();
	void ordenarTerminos();

};






#endif
