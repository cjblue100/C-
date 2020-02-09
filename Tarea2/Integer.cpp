#include "Integer.h"
#include <iostream>
using std::cout;

integer::integer() {

}

integer::integer(int _ingre) 
{
	setInt(_ingre);
}

void integer::setInt(int _ingre)
{
	this->integral = _ingre;
}

int integer::getInt() 
{
	return this->integral;
}

Tipo integer::getTipo()
{
	return Tipo:: Tinteger;
}

void integer::imprimir()
{
	cout << "Integral: " << getInt();
}