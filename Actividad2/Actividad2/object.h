#pragma once

#ifndef OBJECT_H
#define OBJECT_H
#include "object.h"

enum Tipo {Tinteger, Tchar,Tstring};

class object 
{
public:
	virtual Tipo getTipo() = 0;
	virtual void imprimir() = 0;
};




#endif // !OBJECT_H

