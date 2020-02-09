#pragma once
#ifndef STRING_H
#define STRING_H
#include "object.h"
#include <string>
using namespace std;
class String : public object
{
public:
	String();
	String(string);
	~String();

	string arreglo[5][1] ;
	void setString(string);
	string getString();
	Tipo getTipo();
	virtual void imprimir();


};


#endif // !CHAR_H

