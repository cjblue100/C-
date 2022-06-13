#pragma once
#ifndef CHAR_H
#define CHAR_H
#include "object.h"
class Char : public object
{
public:
	Char();
	Char(char);
	~Char();

	char chara;
	
	void setChar(char);
	char getChar();
	Tipo getTipo();
	virtual void imprimir();
};


#endif // !CHAR_H

