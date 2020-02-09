#include "Char.h"
#include <iostream>
using std::cout;

Char::Char() {

}

Char::Char(char _ingre)
{
	setChar(_ingre);
}

void Char::setChar(char _ingre)
{
	this->chara = _ingre;
}

char Char::getChar()
{
	return this->chara;
}

Tipo Char::getTipo()
{
	return Tipo::Tchar;
}

void Char::imprimir()
{
	cout << "Char: " << getChar();
}