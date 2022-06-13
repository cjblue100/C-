#include "numero.h"

numero::numero() :valor(0),valorB(0)
{}

std::ostream& operator<<(std::ostream& out,const numero& n)
{
	out << n.valor;
	return out;
}

std::istream& operator>>(std::istream& in, numero& n)
{
	in >> n.valor;
	return in;
}

numero& operator+(const numero& a, const numero& b)
{
	numero suma;


	suma.valor = a.valor + b.valor;

	return suma;
}
//
//numero::numero(int valor,int valor2)
//{
//	this->valor = valor;
//	this->valorB = valor2;
//}
//
//numero& operator+(const numero& a, const int& b)
//{
//	numero suma;
//	suma.valor = a.valor + b;
//	return suma;
//}
//
//numero& numero::operator++()//preincremento
//{
//	this->valor = this->valor + 1;
//	return *this;
//}
//
//numero& numero::operator++(int)
//{
//	numero resultado = *this;
//
//	this->valor = this->valor + 1;
//
//	return resultado;
//}