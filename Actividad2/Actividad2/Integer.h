#pragma once

#ifndef INTEGER_H
#define INTEGER_H
#include "object.h"
#include <string>
using namespace std;

class integer : public object
{
public:
	integer();
	integer(int);
	//~integer();

	int integral;
	void setInt(int);
	int getInt();
	Tipo getTipo();
	virtual void imprimir();
};



#endif
