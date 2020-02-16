#include<iostream>
#include "Racional.h"

Racional::Racional() :numerador(0), denominador(0) {}

Racional::Racional(int num, int den)
{
	this->numerador = num;
	this->denominador = den;
}

std::ostream& operator<<(std::ostream& out, const Racional& n)
{
	out << n.numerador << "/" << n.denominador;
	return out;
}

Racional& operator+(const Racional& a, const Racional& b)
{
	Racional suma;
	if (a.denominador == b.denominador)
	{
		suma.numerador = a.numerador + b.numerador;
		suma.denominador = a.denominador;
		return suma;
	}
	else if (a.denominador != b.denominador)
	{
		suma.denominador = a.denominador * b.denominador;
		suma.numerador = ((suma.denominador / a.denominador) * a.numerador) + ((suma.denominador / b.denominador) * b.numerador);
		return suma;
	}
	return suma;

}

Racional& operator-(const Racional& a, const Racional& b)
{
	Racional resta;
	if (a.denominador == b.denominador)
	{
		resta.denominador = a.denominador;
		resta.numerador = a.numerador - b.numerador;
		return resta;
	}
	else if (a.denominador != b.denominador)
	{
		resta.denominador = a.denominador * b.denominador;
		resta.numerador = ((resta.denominador / a.denominador) * a.numerador) - ((resta.denominador / b.denominador) * b.numerador);
		return resta;
	}
	return resta;
}

Racional& operator*(const Racional& a, const Racional& b)
{
	Racional producto;
	producto.numerador = a.numerador * b.numerador;
	producto.denominador = a.denominador * b.denominador;
	return producto;
}

Racional& operator/(const Racional& a, const Racional& b)
{
	Racional dividir;
	dividir.numerador = a.numerador * b.denominador;
	dividir.denominador = a.denominador * b.numerador;
	return dividir;
}



