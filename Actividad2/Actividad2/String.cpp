#include "String.h"
#include <iostream>
using std::cout;

String::String() {

}

String::String(string _ingre)
{
	setString(_ingre);
}

void String::setString(string _ingre)
{
	this->arreglo[1][10] = _ingre;
}

string String::getString()
{
	return this->arreglo[1][10];
}

Tipo String::getTipo()
{
	return Tipo::Tstring;
}

void String::imprimir()
{
	cout << "String: " << getString();
}